import sys
import struct

def disassemble(binary_code):
    assembly_code = []

    for i in range(0, len(binary_code), 4):
        instruction = int.from_bytes(binary_code[i:i+4], byteorder='little')

        opcode = instruction & 0x7F

        if opcode == 0x33:  
            rd = (instruction >> 7) & 0x1F

            rs1 = (instruction >> 15) & 0x1F
            rs2 = (instruction >> 20) & 0x1F

            funct3 = (instruction >> 12) & 0x7
            funct7 = (instruction >> 25) & 0x7F

            if funct3 == 0x0 and funct7 == 0x0:
                mnemonic = "add"
            elif funct3 == 0x0 and funct7 == 0x20:
                mnemonic = "sub"
            elif funct3 == 0x1 and funct7 == 0x0:
                mnemonic = "sll"
            elif funct3 == 0x5 and funct7 == 0x0:
                mnemonic = "srl"
            elif funct3 == 0x5 and funct7 == 0x20:
                mnemonic = "sra"
            elif funct3 == 0x6 and funct7 == 0x0:
                mnemonic = "or"
            elif funct3 == 0x7 and funct7 == 0x0:  
                mnemonic = "and"
            elif funct3 == 0x4 and funct7 == 0x0:  
                mnemonic = "xor"
            elif funct3 == 0x2 and funct7 == 0x0:
                mnemonic = "slt"
            elif funct3 == 0x3 and funct7 == 0x0:
                mnemonic = "sltu"
            
            else:
                mnemonic = "unknown instruction"

            assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} {mnemonic} x{rd}, x{rs1}, x{rs2}")


        elif opcode == 0x13:
            rd = (instruction >> 7) & 0x1F
            rs1 = (instruction >> 15) & 0x1F

            funct3 = (instruction >> 12) & 0x7

            imm = (instruction >> 20) & 0xFFF  
            
            if imm & 0x800:
                imm =imm-0x1000

            if funct3 == 0x0:
                mnemonic = "addi"
            elif funct3 == 0x1:
                mnemonic = "slli"
            elif funct3 == 0x5 and instruction >> 25 == 0x00:
                mnemonic = "srli"
                assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} {mnemonic} x{rd}, x{rs1}, {imm}")
            elif funct3 == 0x5 and instruction >> 25 == 0x20:
                mnemonic = "srai"
            elif funct3 == 0x7:
                mnemonic = "andi"
            elif funct3 == 0x2:
                mnemonic = "slti"
            elif funct3 == 0x3:
                mnemonic = "sltiu"
            elif funct3 == 0x4:
                mnemonic = "xori"
            elif funct3 == 0x6:
                mnemonic = "ori"
            else:
                mnemonic = "unknown instruction"
            
            # if mnemonic == "srai":
            #     assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} {mnemonic} x{rd}, x{rs1}, 4")
            if mnemonic == "srai":
                imm = (instruction >> 20) & 0xFFF
                imm = imm if imm < 0x800 else imm - 0x1000
                assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} {mnemonic} x{rd}, x{rs1}, {imm}")
            else:
                assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} {mnemonic} x{rd}, x{rs1}, {imm}")


        elif opcode == 0x63:
            imm = ((instruction >> 31) << 12) | ((instruction >> 7) & 0x1) << 11 | ((instruction >> 25) & 0x3F) << 5 | ((instruction >> 8) & 0xF) << 1
            imm = imm if imm < 0x1000 else imm - 0x2000

            rs1 = (instruction >> 15) & 0x1F
            rs2 = (instruction >> 20) & 0x1F

            funct3 = (instruction >> 12) & 0x7  
            if funct3 == 0x0:
                mnemonic = "beq"
            elif funct3 == 0x1:
                mnemonic = "bne"
            elif funct3 == 0x4:
                mnemonic = "blt"
            elif funct3 == 0x5:
                mnemonic = "bge"
            elif funct3 == 0x6:
                mnemonic = "bltu"
            elif funct3 == 0x7:
                mnemonic = "bgeu"
            else:
                mnemonic = "unknown instruction"  

            assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} {mnemonic} x{rs1}, x{rs2}, {imm}")
        

        elif opcode == 0x37:  
            rd = (instruction >> 7) & 0x1F
            imm = (instruction >> 12) & 0xFFFFF  
            imm <<= 12  

            if imm & 0x80000000:  #   부호비트찾기
                imm -= 0x100000000  # 부호조정
            
    
            assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} lui x{rd}, {imm}")
        
        elif opcode == 0x17:
            rd = (instruction >> 7) & 0x1F

            imm = ((instruction >> 12) & 0xFFFFF) << 12
            if imm & 0x80000000:  
                imm = imm | 0xFFF00000  
                
            assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} auipc x{rd}, {imm}")

        elif opcode == 0x6F:
            rd = (instruction >> 7) & 0x1F

            imm = ((instruction >> 31) << 20) | ((instruction >> 12) & 0xFF) << 12 | ((instruction >> 20) & 0x1) << 11 | ((instruction >> 21) & 0x3FF) << 1
            imm = imm if imm < 0x100000 else imm - 0x200000  
            
            assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} jal x{rd}, {imm}")

        elif opcode == 0x67:
            rd = (instruction >> 7) & 0x1F
            rs1 = (instruction >> 15) & 0x1F
            
            imm = (instruction >> 20) & 0xFFF
            imm = imm if imm < 0x800 else imm - 0x1000
            assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} jalr x{rd}, {imm}(x{rs1})")

        elif opcode == 0x3:
            rd = (instruction >> 7) & 0x1F
            rs1 = (instruction >> 15) & 0x1F

            imm = (instruction >> 20) & 0xFFF
            imm = imm if imm < 0x800 else imm - 0x1000

            funct3 = (instruction >> 12) & 0x7
            if funct3 == 0x0:
                mnemonic = "lb"
            elif funct3 == 0x1:
                mnemonic = "lh"
            elif funct3 == 0x2:
                mnemonic = "lw"
            elif funct3 == 0x4:
                mnemonic = "lbu"
            elif funct3 == 0x5:
                mnemonic = "lhu"
            else:
                mnemonic = "unknown instruction"
            assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} {mnemonic} x{rd}, {imm}(x{rs1})")

        elif opcode == 0x23:
            rs1 = (instruction >> 15) & 0x1F
            rs2 = (instruction >> 20) & 0x1F

            imm = ((instruction >> 25) & 0x7F) << 5 | ((instruction >> 7) & 0x1F)
            
            if imm & 0x800:
                imm = imm - 0x1000

            funct3 = (instruction >> 12) & 0x7
            if funct3 == 0x0:
                mnemonic = "sb"
            elif funct3 == 0x1:
                mnemonic = "sh"
            elif funct3 == 0x2:
                mnemonic = "sw"
            else:
                mnemonic = "unknown instruction"
            assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} {mnemonic} x{rs2}, {imm}(x{rs1})")


        else:
            assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} unknown instruction")

    return assembly_code


def execute_instructions(binary_code, data_memory=None):
    instruction_memory = bytearray(binary_code)
    registers = [0] * 32
    pc = 0

    registers[0] = 0

    if data_memory is None:
        data_memory = bytearray()

    while pc < len(instruction_memory):
        instruction = int.from_bytes(instruction_memory[pc:pc+4], byteorder='little')

        opcode = instruction & 0x7F

        if opcode == 0x33:  # R-type
            rd = (instruction >> 7) & 0x1F 
            rs1 = (instruction >> 15) & 0x1F 
            rs2 = (instruction >> 20) & 0x1F 

            funct3 = (instruction >> 12) & 0x7 
            funct7 = (instruction >> 25) & 0x7F 

            if funct3 == 0x0 and funct7 == 0x0: # ADD
                registers[rd] = registers[rs1] + registers[rs2]
            elif funct3 == 0x0 and funct7 == 0x20: # SUB
                registers[rd] = registers[rs1] - registers[rs2]
            elif funct3 == 0x1 and funct7 == 0x0: # SLL
                shift_count = registers[rs2] & 0x1F  # 32비트 명령어에서 시프트 카운트를 5비트로 마스킹
                registers[rd] = registers[rs1] << shift_count
                #registers[rd] = registers[rs1] << registers[rs2]
            elif funct3 == 0x5 and funct7 == 0x0: # SRL
                #registers[rd] = registers[rs1] >> registers[rs2]
                shift_count = registers[rs2] & 0x1F  # 32비트 명령어에서 시프트 카운트를 5비트로 마스킹
                registers[rd] = (registers[rs1] & 0xFFFFFFFF) >> shift_count
            #elif funct3 == 0x5 and funct7 == 0x20: # SRA
            #    registers[rd] = registers[rs1] >> registers[rs2]
            elif funct3 == 0x5 and funct7 == 0x20: # SRA
                shift_count = registers[rs2] & 0x1F  # 시프트 카운트를 5비트로 마스킹하여 음수 방지
                #if registers[rs1] & 0x80000000:  # 만약 rs1이 음수라면
                # 음수를 처리하기 위해, 먼저 시프트하고 상위 비트를 적절히 설정
                #    registers[rd] = (registers[rs1] >> shift_count) | (0xFFFFFFFF << (32 - shift_count))
                #else:
        #        양수의 경우 단순히 논리적 시프트
                registers[rd] = registers[rs1] >> shift_count

            elif funct3 == 0x6 and funct7 == 0x0:   # OR
                registers[rd] = registers[rs1] | registers[rs2]
            elif funct3 == 0x7 and funct7 == 0x0:  # AND
                registers[rd] = registers[rs1] & registers[rs2]
            elif funct3 == 0x4 and funct7 == 0x0:   # XOR
                registers[rd] = registers[rs1] ^ registers[rs2]
            elif funct3 == 0x2 and funct7 == 0x0:  # SLT
                registers[rd] = int(registers[rs1] < registers[rs2])
            else: 
                print("Unknown instruction")

            pc += 4

        elif opcode == 0x13:  # I-type
            rd = (instruction >> 7) & 0x1F
            rs1 = (instruction >> 15) & 0x1F

            funct3 = (instruction >> 12) & 0x7

            imm = (instruction >> 20) & 0xFFF

            if imm & 0x800: # Sign extension
                imm = imm - 0x1000

            if funct3 == 0x0: # ADDI
                registers[rd] = registers[rs1] + imm

            elif funct3 == 0x1: # SLLI
                #registers[rd] = registers[rs1] << imm
                # imm 값의 상위 7비트가 모두 0인지 확인
                if instruction >> 25 == 0x00:
                    registers[rd] = registers[rs1] << (imm & 0x1F)  # 0x1F는 5비트 마스크
                else:
                    raise ValueError("SLLI 명령어의 imm 값의 상위 7비트가 모두 0이 아닙니다.")


            elif funct3 == 0x5 and instruction >> 25 == 0x00: # SRLI
                #registers[rd] = registers[rs1] >> imm 
                registers[rd] = (registers[rs1] & 0xFFFFFFFF) >> imm

            elif funct3 == 0x5 and (instruction >> 25) == 0x20: # SRAI
                registers[rd] = registers[rs1] >> (imm & 0x1F)
                # imm 값의 상위 7비트가 0x20(0b0100000)인지 확인
                #if (imm >> 5) & 0x7F == 0x20:  # 0x7F는 7비트 마스크
                #    registers[rd] = registers[rs1] >> (imm & 0x1F)
                #else:
                #    raise ValueError("SRAI 명령어의 imm 값의 상위 7비트가 0b0100000이 아닙니다.")
    
            elif funct3 == 0x7: # ANDI
                registers[rd] = registers[rs1] & imm
            elif funct3 == 0x2: # SLTI
                registers[rd] = int(registers[rs1] < imm) 
            #elif funct3 == 0x2: # SLTI
            #    registers[rd] = int((registers[rs1] < imm) and (registers[rs1] < 0) == (imm < 0))
            elif funct3 == 0x4: # XORI
                registers[rd] = registers[rs1] ^ imm
            elif funct3 == 0x6: # ORI
                registers[rd] = registers[rs1] | imm
            else: 
                print("Unknown instruction")

            pc += 4

        elif opcode == 0x37:  # U-type # LUI
            rd = (instruction >> 7) & 0x1F 
            imm = (instruction >> 12) & 0xFFFFF 
            imm <<= 12 
            if rd != 0:
                registers[rd] = imm
            pc += 4 


            #registers[rd] = imm 
            # if imm & 0x80000000:  # Sign extension
            #     imm -= 0x100000000


        elif opcode == 0x17:  # U-type  # AUIPC
            rd = (instruction >> 7) & 0x1F
            imm =(instruction & 0xFFFFF000)
            if rd != 0:
                registers[rd] = pc + imm
            pc += 4

            #imm = ((instruction >> 12) & 0xFFFFF) << 12 
            #if imm & 0x80000000: # Sign extension
                #imm = imm | 0xFFF00000
            #    imm = imm - 0x100000000

        elif opcode == 0x6F:  # J-type # JAL
            rd = (instruction >> 7) & 0x1F  
            imm=((instruction >>31 )<<20) | (((instruction >>21) & 0x3FF) << 1) | (((instruction >>20) & 0x1) << 11) | (((instruction >>12) & 0xFF) << 12)
            imm = imm if imm < 0x100000 else imm - 0x200000

            if rd != 0:
                registers[rd] = pc + 4
            pc += imm

            #imm = ((instruction >> 31) << 20) | ((instruction >> 12) & 0xFF) << 12 | ((instruction >> 20) & 0x1) << 11 | ((instruction >> 21) & 0x3FF) << 1

        elif opcode == 0x67:  # I-type # JALR
            rd = (instruction >> 7) & 0x1F
            rs1 = (instruction >> 15) & 0x1F

            imm = (instruction >> 20) & 0xFFF
            imm = imm if imm < 0x800 else imm - 0x1000
            if rd != 0:
                registers[rd] = pc + 4
            pc = (registers[rs1] + imm) & 0xFFFFFFFE

        elif opcode == 0x3:  # I-type # LOAD
            rd = (instruction >> 7) & 0x1F
            rs1 = (instruction >> 15) & 0x1F

            imm = (instruction >> 20) & 0xFFF 
            imm = imm if imm < 0x800 else imm - 0x1000

            funct3 = (instruction >> 12) & 0x7
            if funct3 == 0x0: # LB
                address = registers[rs1] + imm
                registers[rd] = int.from_bytes(data_memory[address:address+1], byteorder='little', signed=True)
            elif funct3 == 0x1: # LH
                address = registers[rs1] + imm
                registers[rd] = int.from_bytes(data_memory[address:address+2], byteorder='little', signed=True)
            elif funct3 == 0x2: # LW
                address = registers[rs1] + imm
                registers[rd] = int.from_bytes(data_memory[address:address+4], byteorder='little', signed=True)
            elif funct3 == 0x4: # LBU
                address = registers[rs1] + imm
                registers[rd] = int.from_bytes(data_memory[address:address+1], byteorder='little', signed=False)
            elif funct3 == 0x5: # LH
                address = registers[rs1] + imm
                registers[rd] = int.from_bytes(data_memory[address:address+2], byteorder='little', signed=False)
            else:
                print("Unknown instruction")

            pc += 4

        elif opcode == 0x23:  # S-type # STORE
            rs1 = (instruction >> 15) & 0x1F
            rs2 = (instruction >> 20) & 0x1F

            imm = ((instruction >> 25) & 0x7F) << 5 | ((instruction >> 7) & 0x1F)

            if imm & 0x800:
                imm = imm - 0x1000

            funct3 = (instruction >> 12) & 0x7
            if funct3 == 0x0: # SB
                address = registers[rs1] + imm
                data_memory[address:address+1] = registers[rs2].to_bytes(1, byteorder='little', signed=True)
            elif funct3 == 0x1: # SH
                address = registers[rs1] + imm
                data_memory[address:address+2] = registers[rs2].to_bytes(2, byteorder='little', signed=True)
            elif funct3 == 0x2: # SW
                address = registers[rs1] + imm
                data_memory[address:address+4] = registers[rs2].to_bytes(4, byteorder='little', signed=True)
            else:
                print("Unknown instruction")

            pc += 4

        elif opcode == 0x63:  # SB-type
            imm = ((instruction >> 31) << 12) | ((instruction >> 7) & 0x1) << 11 | ((instruction >> 25) & 0x3F) << 5 | ((instruction >> 8) & 0xF) << 1
            imm = imm if imm < 0x1000 else imm - 0x2000

            rs1 = (instruction >> 15) & 0x1F
            rs2 = (instruction >> 20) & 0x1F

            funct3 = (instruction >> 12) & 0x7
            if funct3 == 0x0: # BEQ
                if registers[rs1] == registers[rs2]:
                    pc += imm
                else:
                    pc += 4
            elif funct3 == 0x1: # BNE
                if registers[rs1] != registers[rs2]:
                    pc += imm
                else:
                    pc += 4
            elif funct3 == 0x4: # BLT
                if registers[rs1] < registers[rs2]:
                    pc += imm
                else:
                    pc += 4
            elif funct3 == 0x5: # BGE
                if registers[rs1] >= registers[rs2]:
                    pc += imm
                else:
                    pc += 4
            elif funct3 == 0x6: # BLTU
                if registers[rs1] < registers[rs2]:
                    pc += imm
                else:
                    pc += 4
            elif funct3 == 0x7: # BGEU
                if registers[rs1] >= registers[rs2]:
                    pc += imm
                else:
                    pc += 4
            else:
                print("Unknown instruction")

        else:
            print("Unknown instruction")
        registers[0] = 0
    return registers


def main():
    if len(sys.argv) < 3 or len(sys.argv) > 4:
        print("Usage: python proj2_riscv-sim.py <instruction_file> [<data_file>] <num_instructions>")
        return

    instruction_file = sys.argv[1]
    data_file = sys.argv[2] if len(sys.argv) == 4 else None
    num_instructions = int(sys.argv[-1])

    try:
        with open(instruction_file, "rb") as f:
            binary_code = f.read()

        if data_file is not None:
            with open(data_file, "rb") as f:
                data_memory = bytearray(f.read())
        else:
            data_memory = None
        

        registers =[0] * 32
        registers = execute_instructions(binary_code, data_memory)
        registers[0] = 0

        # for i, register_value in enumerate(registers):
        #     print(f"x{i}: {register_value}")
        for i, val in enumerate(registers):
            if val < 0:
                hex_val= f"0x{(val+(1<<32)) & 0xFFFFFFFF:08x}"
            else:
                hex_val= f"0x{val:08x}"
            print(f"x{i}: {hex_val}")
        

    except FileNotFoundError:
        print("File not found.")


if __name__ == "__main__":
    main()