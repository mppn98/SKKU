// puts and printf:
// puts와 printf 함수의 사용법 비교, 차이점 설명, 또는 이를 활용한 출력 프로그램 작성 문제가 예상됩니다.
puts 함수는 문자열을 출력하고 줄 바꿈(newline)을 자동으로 추가
printf는 다양한 형식의 데이터를 출력하며 개행 문자를 명시적으로 추가
// Pointer arithmetics:
// 포인터 연산을 사용하여 특정 작업을 수행하는 프로그램 작성 문제가 나올 수 있습니다. 예를 들어 배열 요소 접근, 포인터 증가/감소 등과 관련된 문제입니다.


// Member variables in a structure:
// 구조체 내 멤버 변수를 사용하는 프로그램 작성 또는 구조체의 정의와 멤버 변수 접근 방법을 묻는 문제가 나올 수 있습니다.
구조체 내부에 int 변수 3개 (x, y, z)가 선언되어 있을 때, 구조체 배열에서 arr[0].y의 주소를 vPtr이 가리키고 있다고 가정합니다. 
arr[1].y의 주소를 가리키기 위해 vPtr을 얼마만큼 증가시켜야 하는지 계산하는 문제
--구조체 크기는 3*4=12바이트. arr[1].y를 가리키려면 vPtr을 12 바이트(구조체 크기)만큼 증가시켜야함
-- vPtr은 int 타입 포인터이기 때문에 +3 하면 3 * 4 = 12 바이트가 증가

// Advantages of linked lists:
// 연결 리스트의 장점에 대해 설명하는 주관식 문제나, 연결 리스트를 구현하는 프로그램 작성 문제가 예상됩니다.
1.연결 리스트에서 요소의 삽입 및 삭제는 리스트의 중간에서 수행될 때도 (O(1))이 걸립니다. 
배열에서는 이 작업이 (O(n))
2.연결 리스트는 동적으로 크기를 할당하고 해제할 수 있으며 초기 크기를 정의할 필요없다.
// Modes in fopen() function:
// fopen() 함수의 모드에 대한 설명이나, 파일을 열고 읽고 쓰는 프로그램 작성 문제가 나올 수 있습니다.
"r": 읽기 모드. 파일이 존재해야 합니다.
"w": 쓰기 모드. 파일이 존재하지 않으면 새로 생성하고, 존재하면 내용을 지우고 새로 작성합니다.
"a": 추가 모드. 파일이 존재하지 않으면 새로 생성하고, 존재하면 파일 끝에 내용을 추가합니다.
"r+": 읽기/쓰기 모드. 파일이 존재해야 합니다.
"w+": 읽기/쓰기 모드. 파일이 존재하지 않으면 새로 생성하고, 존재하면 내용을 지우고 새로 작성합니다.
"a+": 읽기/추가 모드. 파일이 존재하지 않으면 새로 생성하고, 존재하면 파일 끝에 내용을 추가합니다.


// [24Final] Prime Counter:
// 주어진 범위 내에서 소수의 개수를 세는 프로그램 작성 문제가 나올 것입니다.
#include <stdio.h>

// 소수 판별 함수
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// 주어진 범위 내의 소수 개수를 세는 함수
int countPrimes(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int start, end;
    
    // 사용자로부터 입력 받기
    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);
    
    // 소수 개수 계산
    int primeCount = countPrimes(start, end);
    
    // 결과 출력
    printf("Number of primes between %d and %d: %d\n", start, end, primeCount);
    
    return 0;
}


//[W13] Problem 1 - n prime numbers
#include <stdio.h>
#include <stdlib.h>

int *get_primes(int n)
{
	int *primes = (int *)malloc(n * sizeof(int));
	int count = 0;
	int num = 2;
	while (count < n)
	{
		int is_prime = 1;
		for (int i = 2; i * i <= num; i++)
		{
			if (num % i == 0)
			{
				is_prime = 0;
				break;
			}
		}
		if (is_prime)
		{
			primes[count++] = num;
		}
		num++;
	}
	return primes;
}

int main()
{
	int num, *prime_numbers;
	scanf("%d", &num);

	prime_numbers = get_primes(num);

	for (int i = 0; i < num; i++)
		printf("%d ", prime_numbers[i]);
	printf("\n");

	free(prime_numbers);
	return 0;
}

// [24Final] Reverse Only Numbers All:
// 문자열 내에서 숫자만 역순으로 배치하는 프로그램 작성 문제가 나올 수 있습니다.

void reverseNumbersInString(char *str) {
    int len = strlen(str);
    int i, j;
    
    // 숫자를 저장할 배열과 인덱스
    char numbers[len];
    int numIndex = 0;

    // 숫자만 추출하여 배열에 저장
    for (i = 0; i < len; i++) {
        if (isDigit(str[i])) {
            numbers[numIndex++] = str[i];
        }
    }

    // 숫자를 역순으로 원래 문자열에 재배치
    for (i = 0, j = numIndex - 1; i < len; i++) {
        if (isDigit(str[i])) {
            str[i] = numbers[j--];
        }
    }
}

int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// [24Final] Product of Min and Max:
// 주어진 숫자 리스트에서 최솟값과 최댓값을 찾아 그들의 곱을 계산하는 프로그램 작성 문제가 예상됩니다.
int main() {
    int arr[] = {3, 1, 5, 7, 9, 2, 8, 6}; // 예제 숫자 리스트
    int size = sizeof(arr) / sizeof(arr[0]);

    int product = productOfMinAndMax(arr, size);
    printf("Product of Min and Max: %d\n", product);

    return 0;
}

int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int productOfMinAndMax(int arr[], int size) {
    int min = findMin(arr, size);
    int max = findMax(arr, size);
    return min * max;
}

// [24Final] Term Evaluator:
// 주어진 수식(예: 후위 표기법 등)을 평가하여 결과를 계산하는 프로그램 작성 문제가 나올 수 있습니다.
//[W13] Problem 3 - Bubble Sort              wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

#include <stdio.h>
#define SIZE 10

// You can reuse the move_max function in the last WA.
void move_max(int *array)
{   
    // for( int i = 0; i < SIZE - 1; i++ ){
	// 	if( array[i] > array[i+1] ){
	// 		int temp = array[i];
	// 		array[i] = array[i+1];
	// 		array[i+1] = temp;
	// 	}

	for (int i = 0; i < SIZE - 1; i++)
	{
		if (*(array + i) > *(array + i + 1))
		{
			int temp = *(array + i);
			*(array + i) = *(array + i + 1);
			*(array + i + 1) = temp;
		}
	}
}

void bubble(int *array)
{

	for (int i = 0; i < SIZE; i++)
	{
		move_max(array);
	}

	return;
}

int main()
{
	int num = 0;
	int array[SIZE];

	for (int i = 0; i < SIZE; i++)
		scanf("%d", &array[i]);

	bubble(array);
	printf("Result:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);
	puts("");

	return 0;
}
// [24Final] Partial Sum:
// 배열의 부분 합을 계산하는 프로그램 작성 문제가 예상됩니다.

// 부분 합을 계산하는 함수

int partialSum(int arr[], int size, int start, int end) {
    if (start < 0 || end >= size || start > end) {
        printf("Invalid indices\n");
        return 0;
    }

    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 예제 배열
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 2; // 시작 인덱스
    int end = 5;   // 종료 인덱스

    int sum = partialSum(arr, size, start, end);
    printf("Partial Sum from index %d to %d is: %d\n", start, end, sum);

    return 0;
}

#include <stdio.h>

typedef struct {
	int int_part;
	int dec_part;
} MYFLOAT;

void init(MYFLOAT* n, int i, int d)
{
	n->int_part = i;
	n->dec_part = d;

}

void print(MYFLOAT n) {	
    printf("%d", n.int_part);
    if (n.dec_part != 0) {
        printf(".");
        // Print the non-zero digits of dec_part
        int temp = n.dec_part;
        while (temp % 10 == 0) {
            temp /= 10;
        }
        printf("%d", temp);
    }
    printf("\n");
}

int main()
{
	MYFLOAT num;
	int i,d;
	scanf("%d %d", &i, &d);
	
	init(&num, i, d);
	print(num);
	
	return 0;
}




