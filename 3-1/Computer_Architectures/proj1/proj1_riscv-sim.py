



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
            
            if mnemonic == "srai":
                assembly_code.append(f"inst {len(assembly_code)}: {instruction:08x} {mnemonic} x{rd}, x{rs1}, 4")
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



def main():
    if len(sys.argv) != 2:
        print("use binary_file")
        return

    binary_file = sys.argv[1]

    try:
        with open(binary_file, "rb") as f:
            binary_code = f.read()
            assembly_code = disassemble(binary_code)
            for instruction in assembly_code:
                print(instruction)


    except FileNotFoundError:
        print("File not found.")



if __name__ == "__main__":
    main()