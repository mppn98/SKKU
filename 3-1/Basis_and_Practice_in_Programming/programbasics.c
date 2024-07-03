
//////////////week 2 실습
// 1번 problem 1 circle-information
int main()
{
#include <stdio.h>
	float radius;
	float pi = 3.14159;
	printf("Enter the radius: ");
	scanf("%f", &radius);
	printf("Diameter of a circle: %f\n", radius * 2);
	printf("Circumference of a circle: %f\n", pi * 2 * radius);
	printf("Area of a circle: %f\n", pi * radius * radius);
	return 0;
}
// 2번 problem 2 show time!
#include <stdio.h>
int main()
{
	int total, hours, minutes, seconds;
	scanf("%d", &total);
	hours = total / 3600;
	minutes = (total % 3600) / 60;
	seconds = (total % 3600) % 60;
	printf("%d:%d:%d", hours, minutes, seconds);

	return 0;
}
// 3번 problem 3 split digits
#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int b = a / 10000;
	a = a - b * 10000;
	int c = a / 1000;
	a = a - c * 1000;
	int d = a / 100;
	a = a - d * 100;
	int e = a / 10;
	a = a - e * 10;
	int f = a;
	printf("%d %d %d %d %d\n", b, c, d, e, f);
	return 0;
}

///////////////week3 연습
// is even
#include <stdio.h>
int main()
{
	int input;
	printf("Input an integer: ");
	scanf("%d", &input);
	int remainder = input % 2;
	switch (remainder)
	{
	case 0: // CHANGE HERE(Even)
		printf("Input %d is Even!", input);
		break;
	case 1: // CHANGE HERE(Odd)
		printf("Input %d is Odd!", input);
		break;
	}
	return 0;
}
// multiple of three
#include <stdio.h>
int main()
{
	int input;
	printf("insert a three-digit integer: ");
	scanf("%d", &input);
	// calculate sum of the three digits.
	int first_digit = (input % 10);
	int second_digit = ((input / 10) % 10);
	int third_digit = ((input / 100) % 10);
	int SUM = first_digit + second_digit + third_digit;
	// Use Switch Case here!
	switch (SUM)
	{
	case 3:
	case 6:
	case 9:
	case 12:
	case 15:
	case 18:
	case 21:
	case 24:
	case 27:
		printf("The input %d is a multiple of three!\n", input);
		break;
	default:
		printf("The input %d is not a multiple of three!\n", input);
	}
}

/////////////week3 실습
// problem 1 triangle inequality
#include <stdio.h>
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int longest_side, sum;
	if (a >= b)
	{
		if (a >= c)
		{
			longest_side = a;
			sum = b + c;
		}
	}
	if (c >= b)
	{
		if (c >= a)
		{
			longest_side = c;
			sum = b + a;
		}
	}
	if (b >= a)
	{
		if (b >= c)
		{
			longest_side = b;
			sum = a + c;
		}
	}
	if (sum > longest_side)
		printf("Possible");
	else
		printf("Impossible");
	return 0;
}
// problem2 registration number
#include <stdio.h>
int main()
{
	int reg_num;
	printf("Enter first seven digit of your resident registration number : ");
	scanf("%d", &reg_num);
	if (reg_num > 9999999)
		return 0;

	int year = reg_num / 100000;
	int month = reg_num / 1000 % 100;
	int day = reg_num / 10 % 100;
	int gender = reg_num % 10;
	if (gender <= 2)
		year += 1900;
	else
		year += 2000;

	printf("You born on %d / %d / %d.\n", year, month, day);

	if (gender == 1)
		printf("Your Gender is male (born 1900-1999)\n");
	if (gender == 2)
		printf("Your Gender is female (born 1900-1999)\n");
	if (gender == 3)
		printf("Your Gender is male (born 2000-present)\n");
	if (gender == 4)
		printf("Your Gender is female (born 2000-present)\n");

	return 0;
}

// problem3 a number with all evens
#include <stdio.h>

int main()
{
	int a, num1;
	scanf("%d", &a);
	num1 = a;
	int b = num1 / 10000;
	num1 = num1 - b * 10000;
	int c = num1 / 1000;
	num1 = num1 - c * 1000;
	int d = num1 / 100;
	num1 = num1 - d * 100;
	int e = num1 / 10;
	num1 = num1 - e * 10;
	int f = num1;
	if (b % 2 == 0 && c % 2 == 0 && d % 2 == 0 && c % 2 == 0 && f % 2 == 0)
		printf("%d is our target.\n", a);
	else
		printf("%d is NOT our target.\n", a);

	return 0;
}

//////////////week 04   연습
// triangle ver.1
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			printf(" ");
		}
		for (int k = 1; k <= 2 * i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}

// count zeros
int main()
{
	int n, i;
	int z_num = 0;
	scanf("%d", &n);

	if (n == 0)
	{
		z_num = 1;
	}
	else
	{
		for (; n > 0; n /= 10)
		{
			if (n % 10 == 0)
			{
				z_num++;
			}
		}
	}
	printf("The number of zeros : %d\n", z_num);
}
// find a prime

#include <stdio.h>
int main()
{
	int num, prime = 1;
	scanf("%d", &num);
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			prime = 0;
			break;
		}
	}
	if (prime)
	{
		printf("prime\n");
	}
	else
	{
		printf("not prime\n");
	}
	return 0;
}
// Find primes

#include <stdio.h>
int main()
{
	int num;
	scanf("%d", &num);

	for (int i = 2; i <= num; i++)
	{
		int prime = 1;
		// i가 소수가아니라면 i의 약수는 무조건 i의 제곱근보다 작거나 같다
		for (int j = 2; j * j <= i; j++)
		{ // j*j<=i인이유는 i의 약수는 무조건 i의 제곱근보다 작거나 같기 때문
			if (i % j == 0)
			{ // i의제곱근보다 작은수들에대해서만 약수를검사
				prime = 0;
				break;
			}
		}
		if (prime)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}
////////////////wee4 실습
//[W04] Problem 1 - Factorial of odd numbers
#include <stdio.h>
int main()
{
	int input;
	scanf("%d", &input);
	printf("i     !\n");

	for (int i = 1; i <= input; i += 2)
	{ // input3이면 1,3
		int result = 1;
		for (int j = 2; j <= i; j++)
		{ // i=1일때 시행x, i=3일때 2,3
			result *= j;
		}
		printf("%-6d%d\n", i, result);
	} //%-6d는 6자리를 확보하고 왼쪽정렬/ 숫자왼쪽정렬후 남은 공간을 공백으로 채움
}
//[W04] Problem 2 - Diamond!
#include <stdio.h>
int main()
{
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//[W04] Problem 3 - Prime number
#include <stdio.h>

int main()
{
	int n;

	scanf("%d", &n);

	int prime = 1;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			prime = 0;
			break;
		}
	}

	if (n <= 1)
	{
		prime = 0;
	}

	if (prime)
	{
		printf("It is a Prime Number.\n", n);
	}
	else
	{
		printf("It is not a Prime Number.\n", n);
	}

	return 0;
}

// week5연습 없음

/////////////week5 실습
// 1번 problem 1 sum-function
#include <stdio.h>
int addNumbers(int a)
{
	int sum = 0;
	for (int i = 1; i <= a; i++)
	{
		sum += i;
	}
	return sum;
}

int main()
{
	int input;
	scanf("%d", &input);
	int output = addNumbers(input);
	printf("Sum = %d", output);
	return 0;
}

// 2번 problem2 combinations with prime-numbers

#include <stdio.h>
int checkPrime(int a)
{
	if (a <= 1)
		return 0;
	for (int i = 2; i <= a / 2; i++)
	{ // 2부터 a/2까지의 숫자로 나눠봄
		if (a % i == 0)
			return 0;
	}
	return 1; // 나누어 떨어지지 않으면 소수
}

int main()
{
	int input;

	scanf("%d", &input);
	int flag = 0;

	for (int i = 2; i <= input / 2; i++)
	{
		if (checkPrime(i) && checkPrime(input - i))
		{
			printf("%d = %d + %d\n", input, i, input - i);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("Not possible\n");

	return 0;
}

// 3번 problem3 reverse printer
/*첫 번째 반복 후에는 reversedNum이 첫 번째 자리 숫자가 되고,
이후의 반복에서는 새로운 자리에 숫자를 추가하기 위해 10을 곱해야 합니다.
따라서 이 코드에서 reversedNum * 10은 새로운 자리를 만들어 주는 역할을 합니다.
처음 반복에서는 여분의 0을 추가하지만,
이후 반복에서는 새로운 자리를 위한 공간을 만들어 줍니다.*/
#include <stdio.h>
// Function to reverse and print the given integer
void reversePrint(int n)
{
	int reversenum = 0;
	while (n > 0)
	{
		reversenum = reversenum * 10 + n % 10;
		n /= 10;
	}
	printf("%d\n", reversenum);
}
int main()
{
	int input;
	scanf("%d", &input);
	reversePrint(input);
	return 0;
}
/////////////////////////////////HW1-2

// 1번.[HW1] Match, Near and Far Numbers
#include <stdio.h>

int main()
{
	int match = 0;
	int near = 0;
	int far = 0;
	int target, num;
	scanf("%d %d", &target, &num);

	int cases;

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &cases);
		int dif = target - cases;
		if (dif == 0)
			match++;
		else if (dif < -3 || dif > 3)
			far++;
		else
			near++;
	}
	printf("%d %d %d\n", match, near, far);

	return 0;
}
// 2번.[HW1] Filtering Out '3'
#include <stdio.h>

int main()
{
	int input;
	scanf("%d", &input);

	for (int i = 1; i <= input; i++)
	{
		int include = 0;
		if (i % 3 != 0)
		{ // 3의배수가 아닌경우에만 실행
			int num = i;

			while (num != 0)
			{
				if (num % 10 == 3)
				{				 // 일의자리숫자 3인지확인
					include = 1; // 3이면 include=1설정하고 종료
					break;
				}
				num = num / 10;
			}
			if (include == 0)
			{ // 현재숫자에 3이포함되어 있지 않다면 실행
				printf("%d ", i);
			}
		}
	}

	return 0;
}

// 3번.[HW1] Prime Factors 소인수
#include <stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%d", i);
			while (n % i == 0)
			{
				n /= i;
			}
			if (n != 1)
			{ // 현재숫자가 더이상 n의약수가 아닐때마다 공백을 출력
				printf(" ");
			}
		}
	}
	if (n > 1)
	{ // 남아있는 마지막소인수 출력
		printf("%d", n);
	}
	printf("\n");
	return 0;
}

// 4번.[HW1] Drawing an hourglass
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if (n <= 0 || n % 2 == 0 || n > 30)
	{
		printf("Invalid Input\n");
	}
	else
	{
		for (int i = n; i >= 1; i = i - 2)
		{
			for (int j = 0; j < (n - i) / 2; j++)
			{
				printf(" ");
			}
			for (int j = 0; j < i; j++)
			{
				if (j % 2 == 0)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		for (int i = 3; i <= n; i = i + 2)
		{
			for (int j = 0; j < (n - i) / 2; j++)
			{
				printf(" ");
			}
			for (int j = 0; j < i; j++)
			{
				if (j % 2 == 0)
				{
					printf("*");
				}
				else
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}

// 5번.[HW1] Adjacent Digits with the Same Parity
#include <stdio.h>

int main()
{
	// 사용자로부터 입력받은 숫자를 저장할 변수
	long long n;
	printf("Enter a positive integer: ");
	scanf("%lld", &n);

	int currentParity, prevParity = -1; // 현재 숫자와 이전 숫자의 Parity를 저장할 변수
	int chunkCount = 0;					// Parity Chunk의 수를 저장할 변수

	while (n > 0)
	{
		// 현재 숫자의 Parity 계산 (0: 짝수, 1: 홀수)
		currentParity = (n % 10) % 2;

		// 이전 숫자의 Parity와 현재 숫자의 Parity가 다르면,
		// 새로운 Parity Chunk를 시작한다.
		if (currentParity != prevParity)
		{
			chunkCount++;
			prevParity = currentParity;
		}

		// 다음 숫자로 넘어간다.
		n /= 10;
	}

	printf("Number of Parity Chunks: %d\n", chunkCount);

	return 0;
}
// 6번. [HW1] Rolling a Number
/*어떤 숫자의 자리수를 회전시키는 것을 "Rolling"이라고 합시다. 사용자로부터 2개의 입력(,)을 받아 숫자의 자릿수를 만큼 회전시키는 C 프로그램을 만드세요.
만약 s가 양수이면 숫자는 오른쪽으로 Rolling되고, s가 음수이면, 숫자는 왼쪽으로 Roling됩니다. */
#include <stdio.h>

int main()
{
	int n, s;
	scanf("%d %d", &n, &s);

	int len = 0; // 변수n의 자릿수계산
	int n1 = n;
	for (; n1 != 0; len++)
	{
		n1 = n1 / 10;
	}
	if (s < 0)
	{ // s가음수면 절대값취하고 len으로 나눈나머지를 s에저장
		s = -s;
		s = s % len;
		s = len - s; // 그리고 len에서 s를뺀값을 s에저장
	}
	else
	{ // s가양수면 s를len으로 나눈나머지를 s에저장
		s = s % len;
	}
	int digit = 1; // 회전할 자릿수를 계산
	for (int i = 0; i < s; i++)
	{
		digit = digit * 10;
	}
	int left = n / digit; // 회전할자리수를 기준으로 왼쪽과 오른쪽을 구분
	int right = n % digit;

	int output = right; // 왼쪽부분을 오른쪽에 붙여 회전할 숫자를 구함

	n1 = left;

	for (; n1 != 0;)
	{
		output *= 10;
		n1 = n1 / 10;
	}
	output += left;
	printf("%0*d\n", len, output); // 빈자리를 0으로 채워서 출력 *는 자릿수를 변수로 받겟다는 의미

	return 0;
}

// week6 연습

//[W6, recursion, Lv1] Calculate the Digit Sum. Recursively!
#include <stdio.h>

int digitSum(int num)
{
	if (num < 10)
	{
		printf("%d = ", num);
		return num;
	}
	else
	{
		int last = num % 10;
		printf("%d + ", last);
		return last + digitSum(num / 10);
	}
}

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d\n", digitSum(a));
	return 0;
}
//[W6, recursion, Lv1] Write a Power Function. Recursively!
#include <stdio.h>

int power(int base, int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	else
	{
		return base * power(base, exponent - 1);
	}
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", power(a, b));
	return 0;
}
//[W6, recursion, Lv1] Count Down to 1. Recursively!
#include <stdio.h>

int countTo1(int num)
{
	printf("Is %d == 1?\n", num);
	if (num == 1)
	{
		printf("%d is 1!\n", num);
		return 1;
	}
	else
	{
		printf("%d is not 1, calling again!\n", num);
		countTo1(num - 1);
	}
}

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d\n", countTo1(a));
	return 0;
}

//[W6, recursion, Lv2] Count Down to 1 faster!
// 어려움

//[W6, recursion, Lv3] Find the number. Recursively!
#include <stdio.h>
#include <stdlib.h>

int MAGIC_NUMBER;

int FindNumber(int start, int finish)
{
	if (start > finish)
	{
		// 찾는 숫자가 없는 경우, 이 경우는 발생하지 않지만 안정성을 위해 추가
		return -1;
	}
	int mid = (start + finish) / 2; // 범위의 중간값 계산
	if (mid == MAGIC_NUMBER)
	{
		// 중간값이 마법의 숫자와 같으면 찾았으므로 반환
		return mid;
	}
	else if (mid > MAGIC_NUMBER)
	{
		// 중간값이 마법의 숫자보다 크면, 왼쪽 부분(작은 쪽) 탐색
		return FindNumber(start, mid - 1);
	}
	else
	{
		// 중간값이 마법의 숫자보다 작으면, 오른쪽 부분(큰 쪽) 탐색
		return FindNumber(mid + 1, finish);
	}
}

int main()
{
	int start, finish;
	scanf("%d %d", &start, &finish);
	printf("%d\n", MAGIC_NUMBER == FindNumber(start, finish));
	return 0;
}

// week6 실습
//[W06] Problem 1 - How many times should we update?
#include <stdio.h>

int cnt = 0; // 전역 변수로 선언

void solve(int num)
{
	if (num == 1)
	{
		return;
	}

	if (num % 2 != 0)
	{
		num = 3 * num + 1;
	}
	else
	{
		num = num / 2;
	}

	cnt++;		// 업데이트 횟수 증가
	solve(num); // 재귀 호출
}

int main()
{
	int num;
	scanf("%d", &num);
	solve(num);
	printf("%d", cnt);
	return 0;
}

//[W06] Problem 2 - Reverse Printer (Recursive)
#define for DO_NOT_USE_FOR_LOOP
#define while DO_NOT_USE_WHILE_LOOP
// do not use 'for' or 'while' in your variable name, either!
#include <stdio.h>
void reversePrint(int number)
{
	if (number == 0)
	{
		return;
	}
	else
	{
		printf("%d", number % 10);
		reversePrint(number / 10);
	}
}
int main()
{
	int input;
	scanf("%d", &input);
	reversePrint(input);
	return 0;
}
//[W06] Problem 3 - Sum of digits of a number (Recursive)
#define for DO_NOT_USE_FOR_LOOP
#define while DO_NOT_USE_WHILE_LOOP
// do not use 'for' or 'while' in your variable name, either!
#include <stdio.h>

int sum_of_digit(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return n % 10 + sum_of_digit(n / 10);
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	printf("Sum of digits in %d is %d\n", num, sum_of_digit(num));
	return 0;
}

// week7 연습
//[W7, getchar, Lv2] Uppercase or Lowercase 3
#include <stdio.h>

int main()
{
	char input_char;

	// Get user input character by character
	printf("Enter a string of uppercase or lowercase alphabets: ");
	while ((input_char = getchar()) != '\n')
	{
		// Check if the character is uppercase
		if (input_char >= 'A' && input_char <= 'Z')
		{
			// Convert uppercase to lowercase by adding 32 to the ASCII value
			input_char = input_char + 32;
		}
		// Check if the character is lowercase
		else if (input_char >= 'a' && input_char <= 'z')
		{
			// Convert lowercase to uppercase by subtracting 32 from the ASCII value
			input_char = input_char - 32;
		}
		// Print the converted character
		printf("%c", input_char);
	}
	printf("\n");

	return 0;
}
//[W7, getchar, Lv3] Alphabet Counter 3
#include <stdio.h>

int main()
{
	int count = 0; // "STAR" 패턴이 발생한 횟수를 저장하는 변수
	int state = 0; // 현재 입력 상태를 나타내는 변수

	char c;
	while ((c = getchar()) != EOF)
	{
		if (state == 0 && c == 'S')
		{ // 'S'가 입력되면 상태를 1로 변경
			state = 1;
		}
		else if (state == 1 && c == 'T')
		{ // 'T'가 입력되면 상태를 2로 변경
			state = 2;
		}
		else if (state == 2 && c == 'A')
		{ // 'A'가 입력되면 상태를 3로 변경
			state = 3;
		}
		else if (state == 3 && c == 'R')
		{			   // 'R'이 입력되면 "STAR" 패턴이 완성됨
			state = 0; // 상태 초기화
			count++;   // "STAR" 패턴 발생 횟수 증가
		}
		else
		{ // 다른 문자가 입력되면 상태를 초기화
			state = 0;
		}
	}

	printf("Number of 'STAR' occurrences: %d\n", count);

	return 0;
}
//[[W7, Random Number Generator, Lv1] Random Number
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test_result(int number, int n)
{
	if (number >= 0 && number <= n)
	{
		printf("VALID\n");
	}
	else
	{
		printf("INVALID\n");
	}
}

int main()
{
	int n;
	int number;

	// 시드값 설정을 위해 현재 시간을 사용
	srand(time(NULL));

	// 양수 n 입력 받기
	printf("Enter a positive integer n: ");
	scanf("%d", &n);

	// 0부터 n까지의 난수 생성
	number = rand() % (n + 1);

	// 생성된 숫자 출력
	printf("Generated number: %d\n", number);

	// 결과 출력
	test_result(number, n);

	return 0;
}
//[W7, Random Number Generator, Lv2] Random Array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test_result(int arr[])
{
	int valid = 1;

	// 조건 1: 배열 요소가 0 ~ 1000 사이의 무작위 숫자인지 확인
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] < 0 || arr[i] > 1000)
		{
			valid = 0;
			break;
		}
	}

	// 조건 2: 모든 배열 요소가 서로 다른지 확인
	for (int i = 0; i < 100 - 1; i++)
	{
		for (int j = i + 1; j < 100; j++)
		{
			if (arr[i] == arr[j])
			{
				valid = 0;
				break;
			}
		}
		if (!valid)
		{
			break;
		}
	}

	// 결과 출력
	if (valid)
	{
		printf("VALID ARRAY\n");
	}
	else
	{
		printf("INVALID ARRAY\n");
	}
}

int main()
{
	int *arr = (int *)malloc(sizeof(int) * 100); // 배열 동적 할당

	// 배열에 무작위 숫자 채우기
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % 1001; // 0부터 1000 사이의 무작위 숫자
	}

	// test_result 함수 호출
	test_result(arr);

	return 0;
}

//[W7, Random Number Generator, Lv1] Test your Luck
int oneToFiveRand()
{
	srand(time(NULL));
	return rand() % 6;
}
int main()
{
	int rand;
	rand = oneToFiveRand();
	printf("%d\n", rand);
	return 0;
}
//[W7, conditional operator, Lv1] Conditional operator3
#include <stdio.h>

int isLowercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else
		return 0;
}

int main()
{
	char c;
	scanf("%c", &c);
	if (isLowercase(c))
		printf("Lowercase\n");
	else
		printf("Not lowercase\n");

	return 0;
}

// week7 실습
//[W07] Problem 1 - Stop rolling!
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int seed;
	scanf("%d", &seed); // 사용가가 입력한 seed값을 받음
	srand(seed);
	int pre = 0;
	int cur = 0;

	while (1)
	{
		cur = rand() % 6 + 1;
		printf("%d ", cur);
		if (cur == pre)
		{
			break;
		}
		pre = cur;
	}
	return 0;
}

//[W07] Problem 2 - Distance between characters.
#include <stdio.h>

int main()
{
	char ch1, ch2;
	scanf("%c %c", &ch1, &ch2);

	printf("The distance between %c(%d) and %c(%d) is %d.\n", ch1, ch1, ch2, ch2, ch1 >= ch2 ? ch1 - ch2 : ch2 - ch1);

	return 0;
}

//[W07] Problem 3 - Case converter
#include <stdio.h>

int main()
{
	char ch;
	ch = getchar();

	if (ch >= 'a' && ch <= 'z')
	{
		ch = ch - 'a' + 'A';
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		ch = ch - 'A' + 'a';
	}

	putchar(ch);

	return 0;
}

// 기말 스타트------------------------------------------------------------------


// 9week 연습
//[W9, array basics, Lv1] Add arrays2
#include <stdio.h>
int main()
{

	int arr1[10];
	int arr2[10];
	int results[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr1[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		results[i] = arr1[i] + arr2[9 - i];
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", results[i]);
	}
	return 0;
}

//[W9, comma operator, Lv1] Comma in for loop
#include <stdio.h>
int main()
{

	int n;
	scanf("%d", &n);
	for (int a = 0, b = 0; a < n && b < 2 * n; a++, b = b + 2)
	{
		printf("%d %d\n", a, b);
	}
	return 0;
}

// week9 실습

//[W09] Problem 1 - Swap in an Array
#include <stdio.h>
#define SIZE 10

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	int temp = arr[y];
	arr[y] = arr[x];
	arr[x] = temp;

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

//[W09] Problem 2 - Randomize an Array
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	srand(511);
	int swaps;
	scanf("%d", &swaps);

	int data[SIZE] = {};
	for (int i = 0; i < SIZE; i++)
	{
		data[i] = i;
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", data[i]);
	}
	puts("");
	for (int i = 0; i < swaps; i++)
	{
		int index1 = rand() % SIZE; // 무작위로 SIZE범위 내에서 index1,2를 선택
		int index2 = rand() % SIZE;
		swap(&data[index1], &data[index2]); // index1,2를 swap함수에 넣어서 교환
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", data[i]);
	}
	puts("");

	return 0;
}

//[W09] Problem 3 - Erase Ones
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int seed;
	scanf("%d", &seed);
	srand(seed);

	int data[30] = {};
	for (int i = 0; i < 30; i++)
	{
		data[i] = 1 + rand() % 10;
	}

	for (int i = 0; i < 30; i++)
	{
		printf("%d ", data[i]);
	}
	puts("");
	int count = 0;

	for (int i = 0; i < 30; i++)
	{
		if (data[i] != 1)
		{							 // data의현재 요소가 1이아닌경우
			data[count++] = data[i]; // 해당 요소를 새로운 배열위치에복사
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d ", data[i]);
	}

	puts("");

	return 0;
}

// week10 연습
// Modify the program to print min, max and average values of the survey
#include <stdio.h>
#define RESPONSES_SIZE 40
#define FREQUENCY_SIZE 11

int main()
{
	int frequency[FREQUENCY_SIZE] = {};
	int responses[RESPONSES_SIZE] = {1, 2, 6, 4, 8, 5, 9, 7, 8, 10, 1, 6, 3, 8, 6, 10, 3, 8, 2, 7, 6, 5, 7, 6, 8, 6, 7, 5, 6, 6, 5, 6, 7, 5, 6, 4, 8, 6, 8, 10};
	int min = responses[0], max = responses[0], sum = 0;

	for (size_t answer = 0; answer < RESPONSES_SIZE; answer++)
	{
		frequency[responses[answer]]++;
		if (responses[answer] > max)
		{
			max = responses[answer];
		}
		if (responses[answer] < min)
		{
			min = responses[answer];
		}
		sum += responses[answer];
	}

	printf("%s%17s\n", "Rating", "Frequency");

	for (size_t rating = 1; rating < FREQUENCY_SIZE; rating++)
	{
		printf("%6lu%17d\n", rating, frequency[rating]);
	}
	printf("\nMin: %d, Max: %d, Avg: %.3lf\n", min, max, (double)sum / RESPONSES_SIZE);
	return 0;
}
//[W9, passing arr to func, Lv2] Check prime in an array (ver.1)
#include <stdio.h>
#define length 15

int isPrime(int e)
{
	if (e <= 1)
		return 0;
	for (int i = 2; i * i <= e; i++)
	{
		if (e % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	int array[length];
	for (int i = 0; i < length; i++)
	{
		array[i] = i + 1;
	}

	for (int i = 0; i < length; i++)
	{
		if (isPrime(array[i]))
		{
			printf("%d is prime.\n", array[i]);
		}
	}

	return 0;
}

//[W9, passing arr to func, Lv2] Check prime in an array (ver.2)
#include <stdio.h>
#define length 15

void isArrayPrime(int arr[])
{
	for (int i = 0; i < length; i++)
	{
		int prime = 1;
		if (arr[i] <= 1)
			prime = 0;
		for (int j = 2; j * j <= arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				prime = 0;
				break;
			}
		}
		if (prime)
		{
			printf("%d is prime.\n", arr[i]);
		}
	}
}
int main()
{
	int array[length];
	for (int i = 0; i < length; i++)
		array[i] = i + 1;

	isArrayPrime(array);

	return 0;
}

//[W9, passing arr to func, Lv3] Get meaningful size & sum of an array
/*
We have an array  here. Its maximum size is 10000 which is 'ENOUGH_SIZE' value.
Next, we keep accepting integer  from user and sequentially assign the value of ' % 3' to the  when . When , it means there will be no more user inputs, thus stop assigning.
The original size of the  is 10000 but this size not only implies the size of user inputs but also the number of wasted, redundant spaces.
In this situation, print the array's meaningful size and sum of user inputs by checking .
(The number of user inputs are always less than 'ENOUGH_SIZE')*/
#include <stdio.h>
#define ENOUGH_SIZE 10000

int getsize(int arr[])
{
	int size = 0;
	for (int i = 0; i < ENOUGH_SIZE; i++)
	{
		if (arr[i] % 3 == 0)
		{
			break;
		}
		size++;
	}
	return size;
}
int getSum(int arr[])
{
	int sum = 0;
	for (int i = 0; i < ENOUGH_SIZE; i++)
	{
		if (arr[i] % 3 == 0)
		{
			break;
		}
		sum += arr[i];
	}
	return sum;
}
{
}
int main()
{
	int array[ENOUGH_SIZE];
	int n;
	for (int i = 0; i < ENOUGH_SIZE; i++)
	{
		scanf("%d", &n);
		array[i] = n;
		if (n % 3 == 0)
		{
			break;
		}
	}

	printf("Meaningful size of array is %d\n", getSize(array));
	printf("Meaningful sum of array is %d\n", getSum(array));

	return 0;
}

//[W9, character arrays, Lv1] Print a member of array2
// Make a program that prints last member of the array

#include <stdio.h>
int main()
{

	char Hello[20] = "Hello World!";
	printf("%c\n", Hello[11]);

	return 0;
}

// week10 실습

/*
[W10] Problem 1 - Find max and the index
100점
Write a C program which takes ten nonnegative integers from a user and then finds out the maximum number and the index.
*/
#include <stdio.h>

int main()
{
	int nums[10] = {};

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", nums + i);
	}

	int max = nums[0];
	int maxIndex = 0;

	for (int i = 1; i < 10; i++)
	{
		if (nums[i] > max)
		{
			max = nums[i];
			maxIndex = i;
		}
	}

	printf("Maximum number: %d\n", max);
	printf("Index of maximum number: %d\n", maxIndex);

	return 0;
}

/*
[W10] Problem 2 - Word Length and Reversing
100점
Write a C program that takes a word whose length is between 1 and 100. Print the length of the word and the word in reverse order.
NOTE: Do NOT use string.h for this problem
*/
#include <stdio.h>

int main()
{
	char str[105];
	scanf("%s", str);

	int length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	printf("Word Length: %d\n", length);
	printf("Reversed word: ");
	for (int i = length - 1; i >= 0; i--)
	{
		printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}

// week11 연습
/*
[W10, Multi-D Array, Lv2] Fill the Array - Diagonal
100점
Get two values from user input (please use the provided variables n and m)
and create an array of the dimension m x n.
Then, fill the array using values starting from 0 at arr[0][0] to (m*n - 1) at arr[m-1][n-1] going from top right to bottom left.
*/
#include <stdio.h>

void printArray(int *arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	
    int arr[m][n];
    int num = 0;

    // 배열을 대각선으로 채우기
    for (int diag = 0; diag < m + n - 1; diag++) {
        int row = (diag < n) ? 0 : diag - n + 1;
        int col = (diag < n) ? diag : n - 1;
        while (row < m && col >= 0) {
            arr[row][col] = num++;
            row++;
            col--;
        }
    }

	printArray((int *)arr, m, n);

	return 0;
}

/*
[W10, Multi-D Array, Lv1] 1D Array Index to 2D Array Index
100점
First populate a 10x8 array in the same manner as done in [W10, Multi-D Array, Lv1] Fill the Array - Row Order.
Then, receive an index from user input. The index will be given as if the array was a 1D array (A 2D 10x8 array could be rolled out into a 1D array of size 80). Translate the 1D index into two 2D indices in your 10x8 matrix. In the end, print both indices and the value at that index. Refer to the input/output examples for formatting.
Example:
As 1D Array:
0 1 2 3 4 5 6 7 8
The marked number is at arr[4]
As 2D Array (3x3 Matrix):
0 1 2
3 4 5
6 7 8
The marked number is at arr[1][1]
*/

#include <stdio.h>
#define M 10
#define N 8
int main()
{
	int arr[M][N];
	int count = 0;

	// Populate the array in row order
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = count++;
		}
	}
	/*
	Populate the array in column order
	int arr[m][n];
	int count=0;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < M; i++) {
			arr[i][j] = count++;
		}
	}*/

	// Receive the index from user input
	int index;
	// printf("Enter the index: ");
	scanf("%d", &index);

	// Translate the 1D index into 2D indices
	int row = index / N;
	int col = index % N;

	// Print the indices and the value at that index
	printf("As 2D Array:\n");
	printf("Row: %d\n", row);
	printf("Column: %d\n", col);
	printf("Value: %d\n", arr[row][col]);

	return 0;
}

// week11 실습
/*
[W11] Problem 1 - Rotate a Matrix!
100점
Make a program that
receives 16 numbers from a user,
builds a 4-by-4 array with the input and
prints the original array and the rotated version of the array by 90 degrees.
Check the rotating direction with below examples.
*/
#include <stdio.h>

// Function to print a 4x4 matrix
void printMatrix(int matrix[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

// Function to rotate a 4x4 matrix by 90 degrees clockwise
void rotateMatrix(int matrix[4][4])
{
	// Transpose the matrix
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	// Reverse each row of the transposed matrix
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][3 - j];
			matrix[i][3 - j] = temp;
		}
	}
}

int main()
{
	int matrix[4][4];

	// Input 16 numbers from the user
	printf("Enter 16 numbers:\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	// Print the original matrix
	printf("Original Matrix:\n");
	printMatrix(matrix);

	// Rotate the matrix by 90 degrees clockwise
	rotateMatrix(matrix);

	// Print the rotated matrix
	printf("\nRotated Matrix (90 degrees clockwise):\n");
	printMatrix(matrix);

	return 0;
}

/*
[W11] Problem 2 - Summing or Subtracting a Matrix
100점
Complete the function that receives two 2-by-2 arrays and sets array1 with the sum of the two arrays and array2 with the subtraction.
All elements will be entered by a user and two 2x2 arrays are made by the inputs as in the skeleton code.
Note that summing/subtracting two 2x2 arrays is done by summing/subtracting elements of the same position. (Check the below example.)
Return
*/

#include <stdio.h>

#include <stdio.h>
void sum_arrays(int array1[][2], int array2[][2])
{
	int sum_array[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			sum_array[i][j] = array1[i][j] + array2[i][j];
	int sub_array[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			sub_array[i][j] = array1[i][j] - array2[i][j];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			array1[i][j] = sum_array[i][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			array2[i][j] = sub_array[i][j];
}

int main()
{
	int nums1[2][2], nums2[2][2];

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &nums1[i][j]);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &nums2[i][j]);

	printf("Original Arrays:\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", nums1[i][j]);
		}
		puts("");
	}
	puts("");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%d ", nums2[i][j]);
		puts("");
	}
	puts("");

	sum_arrays(nums1, nums2);

	printf("Returned Arrays:\n");
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%d ", nums1[i][j]);
		puts("");
	}
	puts("");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%d ", nums2[i][j]);
		puts("");
	}
	puts("");

	return 0;
}

/*
[W11] Problem 3 - Correct Errors
100점
Correct the errors in the skeleton code following the directions in the comments.
You might just print '10's with a static code like 'printf("10\n");' to pass the problem, but please try to make use of pointers for your own goods.
You have only one test case for this problem.
*/

#include <stdio.h>

int main()
{
	// Make the pointer p1 point to x1
	// Use p1 to print the value of x1
	int x1, *p1;
	p1 = &x1;
	x1 = 10;
	*p1 = x1;
	printf("%d\n", *p1);
	/*
		int x1, *p1;
		p1= &x1;
		x1 = 10;
		p1 = &x1;
		printf("%d\n", *p1);
		*/

	// Assign 10 to x2 using p2
	// Print the value with x2
	int x2, *p2;
	p2 = &x2;
	*p2 = 10;
	printf("%d\n", x2);

	// Set p3 to point x3 by assigning the address of x3 to p3
	// Assign p3 to p4 to make p3 and p4 point to the same variable, x3
	// Assign 10 to x3 using p4 and print the value with x3
	int x3, *p3, *p4;
	p3 = &x3;
	p4 = p3;
	*p4 = 10;
	printf("%d\n", x3);

	return 0;
}

// week12 강의
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_array(int array[], int n)
{
	// srand(time(0));
	srand(0);
	for (int i = 0; i < n; i++)
		array[i] = rand() % 1000;
}

void print_array(int array[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", array[i]);
	printf("\n");
	return;
}

void min_max(int number[], int size, int *min, int *max)
{
	*min = number[0], *max = number[0];
	/*
	*min = number[0], *max = number[0];
	for(int* p = &number[0]; p <= &number[size-1]; p++) {
	// for(int* p = number; p < number+size; p++) {
	if(*p < *min)
	*min = *p;
	if(*p > *max)
	*max = *p;
	}
	*/
	for (int i = 0; i < size; i++)
	{
		if (number[i] < *min)
			*min = number[i];
		if (number[i] > *max)
			*max = number[i];
	}
}

int main()
{
	int num[10];
	init_array(num, 10);
	print_array(num, 10);
	int min, max;
	min_max(num, 10, &min, &max);
	printf("min: %d, max: %d\n", min, max);
}

// week12 연습
//[W11, Pointer, Lv1] Pointer returning
#include <stdio.h>

int *a(int *x)
{
	int *y;
	y = x;
	return y;
}
int main()
{
	int x = 100;
	int *y;
	int z;

	y = a(&x);

	printf("Value of y is %d", *y);
	return 0;
}
// Max number pointer in array
int *find_max(int array[], int n)
{
	int *max = array;
	for (int i = 1; i < n; i++)
	{
		if (*(array + i) > *max)
			max = array + i;
	}
	return max;
}

int main()
{
	int n;
	int *x;
	int array[100];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", array + i);

	x = find_max(array, n);

	printf("Max num is %d\n", *x);
	return 0;
}

//[W11, Pointer, Lv2] Swap left right
#include <stdio.h>

int swap(int array[], int n)
{
	int temp;
	for (int i = 0; i < n / 2; i++)
	{
		temp = array[i];
		array[i] = array[n - i - 1];
		array[n - i - 1] = temp;
	}
}
int main()
{
	int n;
	int array[100];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", array + i);

	swap(array, n);

	for (int i = 0; i < n; i++)
		printf("%d\n", array[i]);
	return 0;
}

//[W11, Pointer, Lv2] Pick the Prime
#include <stdio.h>

int *pick_prime(int *x, int *y, int *z)
{
	int *result = NULL;

	// x가 소수인지 확인
	int is_x_prime = 1;
	if (*x <= 1)
	{
		is_x_prime = 0; // 1 이하의 숫자는 소수가 아님
	}
	else
	{
		for (int i = 2; i * i <= *x; i++)
		{
			if (*x % i == 0)
			{
				is_x_prime = 0; // x가 소수가 아님
				break;
			}
		}
	}

	// y가 소수인지 확인
	int is_y_prime = 1;
	if (*y <= 1)
	{
		is_y_prime = 0; // 1 이하의 숫자는 소수가 아님
	}
	else
	{
		for (int i = 2; i * i <= *y; i++)
		{
			if (*y % i == 0)
			{
				is_y_prime = 0; // y가 소수가 아님
				break;
			}
		}
	}

	// z가 소수인지 확인
	int is_z_prime = 1;
	if (*z <= 1)
	{
		is_z_prime = 0; // 1 이하의 숫자는 소수가 아님
	}
	else
	{
		for (int i = 2; i * i <= *z; i++)
		{
			if (*z % i == 0)
			{
				is_z_prime = 0; // z가 소수가 아님
				break;
			}
		}
	}

	// x, y, z 중에서 가장 작은 소수를 찾음
	if (is_x_prime)
	{
		result = x;
	}
	if (is_y_prime && (result == NULL || *y < *result))
	{
		result = y;
	}
	if (is_z_prime && (result == NULL || *z < *result))
	{
		result = z;
	}

	return result;
}

int main()
{
	int x, y, z;
	int *result;

	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);

	result = pick_prime(&x, &y, &z);

	if (result)
		printf("First prime number is %d\n", *result);
	else
		printf("There are no prime number\n");
	return 0;
}

//[W11, Call-by-Reference, Lv2] Swap 2
#include <stdio.h>
void swap(int *a, int *b, int *c)
{
	int temp = *a;
	*a = *b;
	*b = *c;
	*c = temp;
}

int main()
{

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	swap(&a, &b, &c);

	return 0;
}

//[W11, Call-by-Reference, Lv1] Get sum of array
#include <stdio.h>
int sum(int *arr)
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
	{
		sum += *(arr + i);
	}
	return sum;
}

int main()
{

	int arr[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", arr + i);
	}

	printf("Sum(arr) returns %d.\n", sum(arr));

	return 0;
}

//[W11, Call-by-Reference, Lv2] Comparing two strings
#include <stdio.h>
#include <string.h>
/*
int string_compare(char *str1, char *str2) {
	strcmp(str1, str2);             //stcmp함수는 문자열의 시작주소를 인자로 받아 두 문자열을 비교하여 같으면 0을 반환한다.
	if(strcmp(str1, str2) == 0)
		return 1;
	else
		return 0;
}*/
int string_compare(char *str1, char *str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return 0;
		}
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{

	char str1[100], str2[100];
	int i;
	for (i = 0; i < 100; i++)
	{
		str1[i] = '\0';
		str2[i] = '\0';
	}

	scanf("%s", str1);
	scanf("%s", str2);

	if (string_compare(str1, str2))
		printf("They are equal.");
	else
		printf("They are not equal.");
}

//[W11, Call-by-Reference, Lv3] Finding the second largest value
#include <stdio.h>

int find_second_largest(int arr[])
{
	int max = arr[0];
	int second_max = arr[0];
	for (int i = 1; i < 5; i++)
	{
		if (arr[i] > max)
		{
			second_max = max;
			max = arr[i];
		}
		else if (arr[i] > second_max)
		{
			second_max = arr[i];
		}
	}
	return second_max;
}

int main()
{

	int arr[5];
	int i;
	for (i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	printf("The second largest value is %d.\n", find_second_largest(arr));

	return 0;
}

/*

주어진 입력 코드를 사용하여 배열의 배열을 만들어야 합니다.
각 배열의 길이를 저장하는 lengths 배열과 배열에 대한 포인터를 저장하는 ptrs 배열을
사용합니다. 첫 번째 줄에는 배열의 수 N이 주어지고, 다음 N개의 줄에는 각 배열의
요소 수 k와 k개의 값이 주어집니다. 따라서 (k+1)개의 정수가 각 줄에 공백으로 구분되어
주어집니다. 모든 배열을 출력해야 합니다. 배열은 한 줄의 공백으로 구분되며,
배열의 요소는 공백으로 구분됩니다. 배열의 길이나 배열의 수를 출력해서는 안 됩니다.
*/
//[W11, Arrays of Pointers, Lv2] Array array
#include <stdio.h>

int main()
{
	int lengths[3], *arrs[3] = {NULL, NULL, NULL};
	int n;
	int arr1[50], arr2[50], arr3[50];

	scanf("%d", &n);
	int idx = 0;
	if (n >= 1)
	{
		scanf("%d", &lengths[idx]);
		for (int i = 0; i < lengths[idx]; i++)
		{
			scanf("%d", &arr1[i]);
		}
		arrs[idx] = arr1;
		idx++;
	}
	if (n >= 2)
	{
		scanf("%d", &lengths[idx]);
		for (int i = 0; i < lengths[idx]; i++)
		{
			scanf("%d", &arr2[i]);
		}
		arrs[idx] = arr2;
		idx++;
	}
	if (n >= 3)
	{
		scanf("%d", &lengths[idx]);
		for (int i = 0; i < lengths[idx]; i++)
		{
			scanf("%d", &arr3[i]);
		}
		arrs[idx] = arr3;
		idx++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < lengths[i]; j++)
		{
			printf("%d ", arrs[i][j]);
		}
		printf("\n");
	}

	return 0;
}

// week12 실습
//[W12] Problem 1 - Array Printer
#include <stdio.h>

void Print(int *source)
{
	printf("Input array: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", *(source + i));
	printf("\n");
}

int main()
{
	int arr[5];

	for (int i = 0; i < 5; i++)
		scanf("%d", arr + i);

	Print(arr);

	return 0;
}

//[W12] Problem 2 - Swap the whole array
#include <stdio.h>

void Swap(int *source, int *dest)
{
	int temp;
	for (int i = 0; i < 5; i++)
	{
		temp = *(source + i);
		*(source + i) = *(dest + i);
		*(dest + i) = temp;
	}

	printf("Source array after swapping: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", *(source + i));

	printf("\n");

	printf("Dest array after swapping: ");
	for (int i = 0; i < 5; i++)
		printf("%d ", *(dest + i));
	printf("\n");
}

int main()
{
	int src[5];
	int dst[5];

	printf("\nEnter 5 elements in source array: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", src + i);

	printf("Enter 5 elements in dest array: ");
	for (int i = 0; i < 5; i++)
		scanf("%d", dst + i);

	Swap(src, dst);
}

//[W12] Problem 3 - Move Max!WWWWWWWWWWWWWWWWWWWWWWWWW
#include <stdio.h>
#define SIZE 10

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

		printf("[%d] ", i + 1);
		for (int j = 0; j < SIZE; j++)
			printf("%d ", array[j]);
		puts("");
	}
}

int main()
{
	int num = 0;
	int array[SIZE];

	for (int i = 0; i < SIZE; i++)
		scanf("%d", &array[i]);

	move_max(array);
	printf("Result:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", array[i]);
	puts("");

	return 0;
}

// week13 연습
//  count the number of words
#include <stdio.h>
#include <string.h>



int CountSpaces(char s[])
{
	int count = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			count++;
	}

	return count;
}

int main()
{
	char str[100] = {0};
	fgets(str, 100, stdin);
	printf("#words=%d\n", CountSpaces(str) + 1);

	return 0;
}
//[W12, Dynamic Memory Allocation, Lv1] Allocation Process
#include <stdlib.h>
#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);

	// Memory Allocation
	int *arr1;
	arr1 = (int *)malloc(n * sizeof(int));

	// Initialization 1
	for (int i = 0; i < n; i++)
		scanf("%d", &arr1[i]);

	// Reallocation
	int *arr2;
	arr2 = (int *)realloc(arr1, 2 * n * sizeof(int));

	for (int i = n; i < 2 * n; i++)
		arr2[i] = arr2[i - n];

	// Print arr2
	for (int i = 0; i < 2 * n; i++)
		printf("%d ", arr2[i]);

	free(arr2);
	return 0;
}

//[W12, Dynamic Memory Allocation, Lv2] Dynamic Size of 2-Dimension Array

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int n, m;
	int **arr;
	scanf("%d %d", &n, &m);
	arr = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int *)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] *= 2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

//[W12, C string, Lv1] Read an entire line
#include <stdlib.h>
#include <stdio.h>
int main()
{
	char sentence[100];
	fgets(sentence, 100, stdin);
	puts(sentence);

	return 0;
}
//[W12, C string, Lv1] using both scanf and fgets
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char s1[10];
	char s2[10];

	scanf("%s", s1);
	while (getchar() != '\n');  // 입력 버퍼에 남아 있는 엔터 키 제거
	puts(s1);
	
	fgets(s2, 10, stdin);
	puts(s2);

	return 0;
}

//[W12, C string, Lv1] make string using getchar()
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char str[11];
	int i = 0;
	while (i < 10)
	{
		char c = getchar();
		if (c == '\n')
		{
			break;
		}
		str[i++] = c;
	}

	puts(str);

	return 0;
}

//[W12, C String Library, Lv1] Comparing Strings
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LEN 20

int main()
{

	char word1[MAX_LEN];
	char word2[MAX_LEN];

	scanf("%s", word1);
	scanf("%s", word2);

	if (strcmp(word1, word2) > 0)
		printf("%s is bigger than %s\n", word1, word2);
	else if (strcmp(word1, word2) < 0)
		printf("%s is bigger than %s\n", word2, word1);
	else
		printf("%s and %s are equal\n", word1, word2);
}

//[W12, C String Library, Lv1] Sort Based on String Length
/*
You are given an array of words with unique lengths. Print the words starting with the shortest one to the longest one. Separate them by spaces.
Use 'Test' and 'Run' function in goorm.*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_WORDS 10

int main()
{

	char *words[NUM_WORDS] = {"Moon", "Car", "Housing", "Miscellaneous",
							  "Rudder", "Programming", "Pointers", "Count", "Christmas", "No"};

	for (int i = 0; i < NUM_WORDS; i++)
	{
		for (int j = i + 1; j < NUM_WORDS; j++)
		{
			if (strlen(words[i]) > strlen(words[j]))
			{
				char *temp = words[i];
				words[i] = words[j];
				words[j] = temp;
			}
		}
	}

	for (int i = 0; i < NUM_WORDS; i++)
	{
		printf("%s ", words[i]);
	}
}

//[W12, C String Library, Lv1] Insert a Word

#include <stdio.h>
#include <string.h>
#define MAX_LEN 100
int main()
{

	char str[MAX_LEN] = "My favourite Programming Language is _. It is so much fun!";
	char insert[MAX_LEN];
	char output[MAX_LEN];

	scanf("%s", insert);

	int len = strlen(str);
	int len2 = strlen(insert);

	int i = 0;
	int j = 0;
	while (i < len)
	{
		if (str[i] == '_')
		{
			for (int k = 0; k < len2; k++)
			{
				output[j++] = insert[k];
			}
			i++;
		}
		else
		{
			output[j++] = str[i++];
		}
	}
	output[j] = '\0';

	printf("%s\n", output);
	return 0;
}
//[W12, C String Library, Lv2] Cut the Sentence
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int main()
{
	char *words[4];
	for (int i = 0; i < 4; i++)
		words[i] = (char *)malloc(sizeof(char) * MAX_LEN);

	char sentence[MAX_LEN * 4] = "Please cut this sentence";

	int i = 0;
	char *token = strtok(sentence, " ");
	while (token != NULL)
	{
		strcpy(words[i++], token);
		token = strtok(NULL, " ");
	}
	for (int i = 0; i < 4; i++)
		printf("%s ", words[i]);
	printf("\n");
	return 0;
}

// week13 실습

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

//[W13] Problem 2 - Count the number of occurrences
/*
Make a program that accepts two strings and count the number of occurrences of the second string(pattern) in the first string(text).
Assumptions:
The max size for both a text and a pattern is 100.
Input strings, including the pattern, can have spaces.
Input strings does NOT have new line characters. (Check the below examples.)
*/
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[100] = {0}, str2[100] = {0};
	int count = 0;

	fgets(str1, 100, stdin);
	fgets(str2, 100, stdin);

	str1[strlen(str1) - 1] = '\0';
	str2[strlen(str2) - 1] = '\0';

	char *ptr = str1;
	while ((ptr = strstr(ptr, str2)) != NULL)
	{
		count++;
		ptr++;
	}

	printf("First string: \"%s\"\nSecond string: \"%s\"\n", str1, str2);
	printf("The number of occurrences is %d.\n", count);

	return 0;
}

//[W13] Problem 3 - Bubble Sort              wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww

#include <stdio.h>
#define SIZE 10

// You can reuse the move_max function in the last WA.
void move_max(int *array)
{
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

// HW2
/*
[HW2] Rotate an array with direction
강의시간때 배운 rotate once function을 활용하여 다음 조건을 만족하는 프로그램을 구현하세요.
'L'을 입력받은 경우 왼쪽으로 array를 한번 회전시키고 출력합니다.
 - PrintArray 함수를 사용해야합니다. (1 2 3 4 --> 2 3 4 1 )
'R'을 입력받은 경우 오른쪽으로 array를 한번 회전시키고 출력합니다.
 - PrintArray 함수를 사용해야합니다. (1 2 3 4 --> 4 1 2 3 )
'F'를 입력받으면 프로그램이 종료됩니다.
 - main 함수를 확인하세요.
그 외의 모든 문자는 무시하세요.
 - 어떤것도 출력해서는 안됩니다.
RotateOnceLR 함수를 완성해 위의 조건을 만족하는 프로그램을 구현하세요.
Input Explanation
Arbitrary uppercase alphabets will be given without any blanks as a single line.
임의의 대문자 알파벳들이 공백 없이 한줄로 주어집니다.
Output Explanation
Print all results of rotating the array with the given directions.
주어진 방향대로 배열을 회전한 결과를 모두 출력하세요.
Input Range Specification
All input values are uppercase alphabets.
모든 입력값은 대문자 알파벳입니다.
*/

#include <stdio.h>
#define N 10

void PrintArray(int array[])
{
	for (int i = 0; i < N; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void RotateOnceLR(int array[], char dir)
{

	if (dir == 'L')
	{
		int temp = array[0];
		for (int i = 0; i < N - 1; i++)
			array[i] = array[i + 1];
		array[N - 1] = temp;
	}
	else if (dir == 'R')
	{
		int temp = array[N - 1];
		for (int i = N - 1; i > 0; i--)
			array[i] = array[i - 1];
		array[0] = temp;
	}
	else
	{
		return;
	}
}

int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	char dir;
	while ((dir = getchar()) != 'F')
	{
		RotateOnceLR(arr, dir);
	}

	return 0;
}
/*
[HW2] Anagram Checker
Problem

사용자로부터 2개의 단어를 입력받고 해당 단어들이 서로 anagram인지 확인하는 Anagram checker 프로그램을 작성하세요.
cf) anagram : 한 단어가 다른 단어의 문자를 재배열하여 만들 수 있다면 anagram이라고 표현합니다. e.g.) spar <-> rasp
Input Explanation
Two words that only consist of lowercase alphabet separated by blanks are given.
공백으로 구분된 소문자 알파벳으로만 이루어진 두개의 단어를 입력받습니다.
만약 두 단어가 anagram이라면 "Anagram!"을, 그렇지 않다면 "Not Anagram!"을 출력하세요.
Input Range Specification
입력받는 단어는 N개의 알파벳 소문자로 이루어져있으며 N은 다음 조건을 만족합니다.
*/

#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 100

int check_anagram(char *word1, char *word2)
{
	int word1_len = strlen(word1);
	int word2_len = strlen(word2);

	int true = 1;
	int false = 0;

	if (word1len != word2_len) // 길이가 다르면 anagram이 아니니까
		return false;

	int count[26] = {
		0,
	};

	for (int i = 0; i < word1_len; i++)
	{
		count[word1[i] - 'a']++;
	}

	for (int i = 0; i < word2_len; i++)
	{
		count[word2[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
			return false;
	}

	return true;
}

int main()
{
	char word1[MAX_WORD_LEN + 1] = {0};
	char word2[MAX_WORD_LEN + 1] = {0};

	scanf("%s", word1);
	scanf("%s", word2);

	if (check_anagram(word1, word2))
		printf("Anagram!");
	else
		printf("Not Anagram!");
}

/*
[HW2] Word Substituter
Problem
Write the substitute_text function of a program that takes a sentence (text) and two words (word1, word2) and replaces word1 in text with word2.
The sentence (text) may contain spaces, and word1 and word2 do not contain spaces.
A word needs to be separated from others by spaces.
e.g. In the following sentence(text) : I am a boy
"oy" is not a word.
"boy" is a word.
Also, it distinguishes between uppercase and lowercase letters
e.g.
"The" and "the" are different word
문장(text)을 입력받고 2개의 단어(word1, word2)를 입력받아 text에 있는 word1을 word2로 대체하는 프로그램의 substitute_text 함수를 구현하시오.
문장(text)에는 공백이 포함될 수 있으며, word1과 word2에는 공백이 포함되지 않습니다.
단어의 기준은 공백으로 구분됩니다.
e.g. 입력으로 주어진 문장(text) : I am a boy
"oy"는 단어가 아닙니다.
"boy"는 단어입니다.
또한 대소문자를 구분합니다.
e.g.
"The"와 "the"는 다른 단어입니다.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substitute_text(char *text, const char *word1, const char *word2)
{

	int text_len = strlen(text);
	int word1_len = strlen(word1);
	int word2_len = strlen(word2);

	char output[500] = {
		0,
	};
	int idx = 0;

	for (int i = 0; i < text_len; i++)
	{
		if (strncmp(text + i, word1, word1_len) == 0)
		{

			for (int j = 0; j < word2_len; j++)
			{
				output[idx++] = word2[j];
			}
			i += word1_len - 1;
		}
		else
		{ // word1이 아니니깐
			output[idx++] = text[i];
		}
	}

	strcpy(text, output);
}

int main()
{
	char text[501] = {0};
	char word1[11] = {0};
	char word2[11] = {0};

	fgets(text, 500, stdin);
	scanf("%s", word1);
	scanf("%s", word2);

	text[strlen(text) - 1] = '\0';

	substitute_text(text, word1, word2);

	printf("%s", text);

	return 0;
}
/*
[HW2] Removing Duplicated Numbers
Problem
배열의 길이 과 의 길이를 가지는 정수 배열 을 입력받으세요.
정수 배열 에서 중복 원소를 제거하는 프로그램을 작성하세요.
중복 원소의 경우 가장 먼저 등장하는 것만 남기는 방식으로 제거되어야 합니다.
Input Explanation
첫 줄에 배열의 길이 이 주어집니다.
다음 줄에 정수 배열 의 원소 개가 공백으로 구분되어 주어집니다.
Output Explanation
중복된 원소가 제거된 정수 배열 의 원소를 공백으로 구분하여 출력하세요.
중복된 원소들 중 가장 먼저 등장한 원소는 남아있어야 합니다.
Input Range Specification
All input values will follow the following rules.
모든 입력값은 다음을 따릅니다.
5<=n<=100
0<=a[i]<=100
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int *newarr = (int *)malloc(101 * sizeof(int));
	for (int i = 0; i < 101; i++)
		newarr[i] = 0;

	for (int i = 0; i < n; i++)
	{
		if (newarr[arr[i]] == 0)
		{
			newarr[arr[i]] = 1;
			printf("%d ", arr[i]);
		}
	}
	printf("\n");

	free(arr);
	free(newarr);
	return 0;
}

/*
[HW2] Mini BBooYo
Problem
미니 뿌요뿌요 프로그램을 작성하시오.
프로그램의 작동 방식은 다음과 같습니다.
1. 숫자 배열의 크기 N을 입력받습니다.
2. 임의의 수가 N개 저장된 배열의 원소를 각각 입력받습니다.
2-1. 각 수 n의 범위는 0 <= n <= 9입니다.
3. 미니 뿌요뿌요의 규칙에 맞게 배열의 수들을 모두 처리한 뒤 남은 수만 출력합니다.
미니 뿌요뿌요의 규칙은 다음과 같습니다.
1. 두개 이상의 같은 값이 연속적으로 있을 경우 해당 수들을 모두 없앱니다.
e.g. 1 2 2 2 3 -> 1 3
2. 이웃한 두 수의 swap을 통해 두 개 이상의 같은 값이 연속적으로 존재할 수 있는 경우 swap한 뒤 1번 규칙을 따릅니다.
e.g. 1 2 3 2 -> 1 3 2 2 -> 1 3
2-1. swap을 한 번 진행한 뒤에는 항상 연속적인 같은 수들을 제거해야합니다. e.g.1. 3 4 3 2 3 -> 4 3 3 2 3 -> 4 2 3 : 가능
e.g.2. 3 4 3 2 3 -> 4 3 3 2 3 -> ... 4 2 3 3 3 -> 4 2 : 불가
3. 규칙 적용은 순차적으로 진행되며 연속된 같은 값의 길이를 swap을 통해 연장할 수 있더라도 swap을 하지 않고 즉시 삭제됩니다.
e.g.1. 3 3 4 3 -> 4 3 : 가능
e.g.2. 3 3 4 3 -> 3 3 3 4 -> 4 : 불가
4. 수 제거 혹은 swap 등 배열의 원소에 변경이 발생할 경우 무조건 0번째 index부터 다시 규칙을 적용합니다.
5. 위의 규칙을 적용했을때 더이상 제거 가능한 수가 없을때까지 반복합니다.
다음은 미니 뿌요뿌요의 규칙을 설명한 예시입니다.
Input
10
1 2 2 3 4 3 3 4 5 3
Output
1. 1 2 2 3 4 3 3 4 5 3 -> 1 3 4 3 3 4 5 3 (2 2 제거)
2. 1 3 4 3 3 4 5 3 -> 1 3 4 4 5 3 (3 3 제거)
3. 1 3 4 4 5 3 -> 1 3 5 3 (4 4 제거)
4. 1 3 5 3 -> 1 5 3 3 (3 5 swap)
5. 1 5 3 3 -> 1 5 (3 3 제거)
Input Explanation
양의 정수 N이 첫 줄에 주어집니다. 두번째 줄에서 N개의 양의 정수를 입력받습니다.
미니 뿌요뿌요의 결과를 출력하세요.
Input Range Specification
The input value will follow the following rules:

입력값은 다음을 따릅니다.
*/

#include <stdio.h>
#include <stdlib.h>

void delete(int *arr, int *len)
{
	int ischange = 0;

	while (1)
	{
		ischange = 0;
		int i = 0;

		while (i < *len)
		{
			int start = i;

			while (i + 1 < *len && arr[i] == arr[i + 1])
			{
				i++;
			}

			if (i > start)
			{
				ischange = 1;
				int samelen = i - start + 1;
				for (int j = start; j + samelen < *len; j++)
				{
					arr[j] = arr[j + samelen];
				}
				*len -= samelen;
				i = 0;
			}
			else
			{
				i++;
			}
		}

		if (!ischange)
		{
			break;
		}
	}
}

void BBooYo(int *arr, int *len)
{
	while (1)
	{
		int now = *len;
		delete (arr, len);

		if (now == *len)
		{
			continue;
		}

		int isswap = 0;

		for (int i = 0; i < *len - 2; i++)
		{
			if (arr[i] != arr[i + 1] && arr[i] == arr[i + 2])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				isswap = 1;
				break;
			}
		}

		if (isswap == 0)
		{
			break;
		}
	}
}

void print_array(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	BBooYo(arr, &n);

	print_array(arr, n);

	free(arr);
	return 0;
}

// week14 연습


/*
[W13, File I/O, Lv2] Read from File!
In this problem, you will read from a file, and print its content.
The file you need to open will be located at "data/input.txt"
Try using fscanf to complete the question.
Use 'Test' and 'Run' function in goorm.
Be careful:
See  Run Screen Example and Input/Output Example carefully
Any typos will make you no credits
Typo include spaces(' '), line breaks('\n'), tabs('\t'), and even null characters('\0').
출력: Hello File I/O! 
*/

#include <stdio.h>
int main(){
	FILE *fp;
	char str[20]={};
	fp = fopen("data/input.txt", "r");
	while(fscanf(fp, "%s", str) != EOF){
		printf("%s ", str);
	}

	fclose(fp);
	return 0;

}

#include <stdio.h>
int main(){
	FILE *fp;
	char str[20]={};
	fp=fopen("data/input.txt", "w");
	for(int i=0; i<10; i++){
		fprintf(fp, "[%d] ", i);
	}
	fclose(fp);
	return 0;

}
#include <stdio.h>
int main(){
	FILE *fp;
	char str[20]= "Hello Append!";
	fp=fopen("data/input.txt", "a");
	fprintf(fp, "%s", str);
	fclose(fp);
	return 0;
}
#include <stdio.h>
int main(){
	FILE *fp,*fp2;
	int num,sum=0;
	fp=fopen("data/input.txt", "r");
	fp2=fopen("data/output.txt", "w");
	while(fscanf(fp, "%d", &num) != EOF){
		sum+=num;
	}
	fprintf(fp2, "%d", sum);
	fclose(fp);
	fclose(fp2);
	return 0;
}
/*
In this problem, you will write to a file, and print its content.
The file you need to open will be located at "data/input.txt"
The input file will consist 10 numbers. Append the sum in the end of input.txt in the format of the example.
Then, print the final result of input.txt
Try using fprintf and fscanf to complete the question.
Use 'Test' and 'Run' function in goorm.
*/
//출력 : 21 41 25 62 73 47 34 73 23 2346 2745
#include <stdio.h>
int main(){
	FILE *fp;
	int num,sum=0;
	fp=fopen("data/input.txt", "r");
	while(fscanf(fp, "%d", &num) != EOF){
		sum+=num;
	}
	fclose(fp);
	fp=fopen("data/input.txt", "a");
	fprintf(fp, " %d", sum);
	fclose(fp);
	return 0;
}
/*출력:
Hello!
Welcome!
Goodbye!
See you soon~
*/
/*
Write a program that generates the output.txt file by copying the input.txt file.
- Multiple lines of string data are written in File input.txt
- File input.txt is at the folder data so you can access to input.txt file by using path data/input.txt.
- Make sure that you make output.txt file at the folder data by using path data/output.txt.
- When code read the output.txt, the output should be like the picture below.*/
#include <stdio.h>
int main(){
	FILE *fp,*fp2;
	char str[20]={};
	fp=fopen("data/input.txt", "r");
	fp2=fopen("data/output.txt", "w");
	while(fgets(str, 20, fp) != NULL){
		fprintf(fp2, "%s", str);
	}
	fclose(fp);
	fclose(fp2);

	fp = fopen("data/output.txt", "r");
	char output[50];
	while (fgets(output, sizeof(output), fp) != 0) {
		printf(output);
	}
	fclose(fp);

	return 0;
}
/*
[W13, File I/O Functions, Lv2] change "mom" to "dad" in the file
Write a program that changes "mom" to "dad" in the string written in the input.txt file, and stores the result in the output.txt file.
- File input.txt is at the folder data so you can access to input.txt file by using path data/input.txt.
- Make sure that you make output.txt file at the folder data by using path data/output.txt.
- When code read the output.txt, the output should be like the picture below.
*/
#include <stdio.h>
int main(){
	FILE *fp,*fp2;
	char str[20]={};
	fp=fopen("data/input.txt", "r");
	fp2=fopen("data/output.txt", "w");
	while(fgets(str, 20, fp) != NULL){
		for(int i=0; i<20; i++){
			if(str[i]=='m' && str[i+1]=='o' && str[i+2]=='m'){
				str[i]='d';
				str[i+1]='a';
				str[i+2]='d';
			}
		}
		fprintf(fp2, "%s", str);
	}
	fclose(fp);
	fclose(fp2);

	fp = fopen("data/output.txt", "r");
	char output[50];
	while (fgets(output, sizeof(output), fp) != 0) {
		printf(output);
	}
	fclose(fp);

	return 0;

}
/*
[W13, File I/O Functions, Lv2] Count "apple"s in the file
Write a program that count the number of words, "apple" in the input.txt file.
- File input.txt is at the folder data so you can access to input.txt file by using path data/input.txt.
*/
#include <stdio.h>
int main(){
	FILE *fp;
	char str[20]={};
	int count=0;
	fp=fopen("data/input.txt", "r");
	while(fscanf(fp, "%s", str) != EOF){
		if(str[0]=='a' && str[1]=='p' && str[2]=='p' && str[3]=='l' && str[4]=='e'){
			count++;
		}
	}
	printf("%d", count);
	fclose(fp);
	return 0;
}
/*
[W13, File I/O, Lv1] Read an integer from byte stream
You got the "data/binary.bin" which has only one integer written in binary stream format.
You need to print out that integer
Use 'Test' and 'Run' function in goorm
*/
#include <stdio.h>
int main(){
	FILE *fp;
	int num;
	fp=fopen("data/binary.bin", "rb");
	fread(&num, sizeof(int), 1, fp);
	printf("%d", num);
	fclose(fp);
	return 0;
}
/*
[W13, File I/O, Lv1] Read the list of integers in byte stream
You got the "data/binary.bin" which has multiple integer in byte stream format.
At first, you get number of integers which is N.
Then N integers are written on file.
You need to print out the sum of integer
1 <= N <= 99
Use 'Test' and 'Run' function in goorm.
*/
#include <stdio.h>
int main(){
	FILE *fp;
	int num,sum=0;
	fp=fopen("data/binary.bin", "rb");
	fread(&num, sizeof(int), 1, fp);
	for(int i=0; i<num; i++){
		int temp;
		fread(&temp, sizeof(int), 1, fp);
		sum+=temp;
	}
	printf("%d", sum);
	fclose(fp);
	return 0;
}

#include <stdio.h>

int test()
{
	FILE *fp1, *fp2;
	int arr1[10], arr2[10];
	
	fp1 = fopen("data/output.bin", "rb");
	fp2 = fopen("data/binary.bin", "rb");

	fread(arr1, 4, 10, fp1);
	fread(arr2, 4, 10, fp2);

	
	for (int i = 0; i < 10; i++) {
		if (arr1[i] != arr2[i])
			return 0;
	}
	
	fclose(fp1);
	fclose(fp2);

	return 1;
}

int main()
{
	FILE *fp;
		
	fp = fopen("data/output.bin", "wb");

	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	fwrite(arr, 4, 10, fp);


	fclose(fp);
	
	if (test())
		printf("Correct\n");
	else
		printf("Failed\n");
	
	return 0;
}


// week14 실습
//[W14] Problem 1 - File copy

#include <stdio.h>
int main()
{
	// Write your code at here
	FILE *fp;

	fp = fopen("data/c11p1_input.txt", "r");
	char input[50];
	fgets(input, 50, fp);
	fclose(fp);

	fp = fopen("data/c11p1_output.txt", "w");
	fputs(input, fp);
	fclose(fp);

	fp = fopen("data/c11p1_output.txt", "r");
	char output[50];
	fgets(output, 49, fp);
	printf(output);
	fclose(fp);
	return 0;
}


//[W14] Problem 2 - File compare
#include <stdio.h>
#include <string.h>

int main() {
	char filename1[20],filename2[20];
	
    printf("Path of first file : ");
    scanf("%s",filename1);

    printf("Path of second file : ");
    scanf("%s", filename2);

	FILE *fp1 =fopen(filename1,"r");
	FILE *fp2 =fopen(filename2,"r");
	
	char ch1,ch2;
	int same=1;

	while(1){
		ch1=fgetc(fp1);
		ch2=fgetc(fp2);
		
		if(ch1==EOF && ch2 !=EOF || ch1!=EOF && ch2 ==EOF){
			same=0;
			break;
		}
		else if(ch1==EOF && ch2 ==EOF){
			break;
		}	
		if(ch1 != ch2){
			same=0;
			break;
		}
	
	}
	
		fclose(fp1);
		fclose(fp2);
	
	if(same){
		printf("Two files are same.\n");
	}
	else{
		printf("Two files are different.\n");
	}
    return 0;
}

//[W14] Problem 3 - File Data Analysis
#include <stdio.h>

int main() {
	printf("\n%5s%7s%7s%7s%7s%7s\n", "NAME","MATH","ENG","SCI","SUM","AVG");
	
	FILE *fp;
	fp = fopen("data/student.txt", "r");
	
	int num_students;
    fscanf(fp, "%d", &num_students);

    char firstname[20];
    int math, eng, sci, sum;
    double average;

    for (int i = 0; i < num_students; i++) {
        fscanf(fp, "%s %d %d %d", firstname, &math, &eng, &sci);
        sum = math + eng + sci;
        average = sum / 3.0;
				printf("%5s%7d%7d%7d%7d%7.2lf\n", firstname, math, eng, sci, sum, average);
		}
	
	fclose(fp);
	
	return 0;
}

// week15 연습
//[W14, Structures, Lv3] Manage the structure 1!
#include <stdio.h>
#include <stdlib.h>

#define NODE_NUM 10
#define SEED 100
#define MAX_VALUE 100

typedef struct _node{
	int value;
	struct _node *next;
}node;

int main() {

	node *head = (node *)malloc(sizeof(node));
	node *cur = head;
	
	srand(SEED);
	
	cur->value = rand() % MAX_VALUE;
	
	// Allocate nodes
	for(int i = 0; i < NODE_NUM; i++){
		cur->next = (node *)malloc(sizeof(node));
		cur = cur->next;
		cur->value = rand() % MAX_VALUE;


	}
	cur = head;
	
	// Print values
	while(cur != NULL){
		printf("value : %d\n", cur->value);
		cur = cur->next;
	}
	
	return 0;
}
////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#define NODE_NUM 10
#define SEED 100
#define MAX_VALUE 100

typedef struct _node{
	int value;
	struct _node *next;
}node;

int main() {

	node *head = (node *)malloc(sizeof(node));
	node *cur = head;
	
	srand(SEED);
	
	cur->value = rand() % MAX_VALUE;
	
	// Allocate nodes
	for(int i = 0; i < NODE_NUM; i++){
		cur->next = (node *)malloc(sizeof(node));
		cur = cur->next;
		cur->value = rand() % MAX_VALUE;
	}
	cur = head;
	
	// Print values
	while(cur != NULL){
		printf("value : %d\n", cur->value);
		cur = cur->next;
	}
	
	return 0;
}
//[W14, Linked list, Lv2] Structure linked list printing
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char* name;
	int score;
	struct node *next;
} NODE;

void print_linked_list(NODE* first){	
	NODE* cur = first;
	while(cur != NULL){
		printf("name : %s, score : %d\n", cur->name, cur->score);
		cur = cur->next;
	}	
}
int main() {

	char NAME_SUWON[] = "Suwon";
	char NAME_SEOUL[] = "Seoul";
	char NAME_SEJONG[] = "Sejong";
	
	NODE *first = (NODE*) malloc(sizeof(NODE));
	NODE *second = (NODE*) malloc(sizeof(NODE));
	NODE *third = (NODE*) malloc(sizeof(NODE));
	
	first->next = second;
	first->name = NAME_SUWON;
	first->score = 5;
	
	second->next = third;
	second->name = NAME_SEOUL;
	second->score = 5;
	
	third->next = NULL;
	third->name = NAME_SEJONG;
	third->score = 7;
	
	print_linked_list(first);	

	return 0;
}
//[W14, Linked list, Lv3] Structure linked list adding
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char* name;
	int score;
	struct node *next;
} NODE;

void print_linked_list(NODE* first){
	NODE* cur = first;
	while(cur != NULL){
		printf("%s %d\n", cur->name, cur->score);
		cur = cur->next;
	}	
}

NODE* get_last_node(NODE* first){
	NODE* cur = first;
	while(cur->next != NULL){
		cur = cur->next;
	}
	return cur;	
}

void append_node(NODE* first, char* name, int score){
	NODE* last = get_last_node(first);
	NODE* new_node = (NODE*) malloc(sizeof(NODE));
	new_node->name = name;
	new_node->score = score;
	new_node->next = NULL;
	last->next = new_node;
	
}

int main() {

	char NAME_SUWON[] = "Suwon";
	char NAME_SEOUL[] = "Seoul";
	char NAME_SEJONG[] = "Sejong";
	
	NODE *first = (NODE*) malloc(sizeof(NODE));
	
	first->next = NULL;
	first->name = NAME_SUWON;
	first->score = 10;
	
	append_node(first, NAME_SEOUL, 10);
	
	append_node(first, NAME_SEJONG, 14);
	
	print_linked_list(first);	

	return 0;
}


//[W14, Linked list, Lv3] Structure linked list adding 2




//[W14, Linked list, Lv4] Structure linked list delete
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char* name;
	int score;
	struct node *next;
} NODE;

NODE* first = NULL;

void print_linked_list();
NODE* get_last_node();
void append_node(char* name, int score);
void attach_node(char* name, int score)


void print_linked_list(){
	NODE* cur = first;
	while(cur != NULL){
		printf("%s %d\n", cur->name, cur->score);
		cur = cur->next;
	}	
}

NODE* get_last_node(){
	if (first == NULL) return NULL; // 리스트가 비어 있는 경우 처리
	NODE* cur = first;
	while(cur->next != NULL){
		cur = cur->next;
	}
	return cur;	
}

void append_node(char* name, int score){
	NODE* last = get_last_node();
	NODE* new_node = (NODE*) malloc(sizeof(NODE));
	new_node->name = name;
	new_node->score = score;
	new_node->next = NULL;
	if (last == NULL) {
        first = new_node; // 리스트가 비어 있는 경우
    } else {
        last->next = new_node;
    }
	
}

void attach_node(char* name, int score){
	NODE* new_node = (NODE*) malloc(sizeof(NODE));
	new_node->name = name;
	new_node->score = score;
	new_node->next = first;
	first = new_node;
}

void delete_node(NODE* target) {
    if (first == NULL || target == NULL) return; // 리스트가 비어 있거나 타겟이 NULL인 경우 처리
    if (target == first) {
        first = first->next;
    } else {
        NODE* prev = first;
        while (prev->next != target && prev->next != NULL) {
            prev = prev->next;
        }
        if (prev->next == target) {
            prev->next = target->next;
        }
    }
    free(target);
}


int main() {

	char NAME_SUWON[] = "Suwon";
	char NAME_SEOUL[] = "Seoul";
	char NAME_SEJONG[] = "Sejong";
	
	first = (NODE*) malloc(sizeof(NODE));
	
	first->next = NULL;
	first->name = NAME_SEOUL;
	first->score = 2;
	
	attach_node(NAME_SUWON, 1);
	
	append_node(NAME_SEJONG, 3);
	
	delete_node(first->next); // seoul
	
	print_linked_list();	
	
	printf("===============\n");
	
	delete_node(first); // suwon
	delete_node(first); // sejong
	
	attach_node("Hi", 1);
	append_node("I'm", 2);
	append_node("new", 3);
	append_node("!", 4);
	
	print_linked_list();	
	
	printf("===============\n");
	
	delete_node(first->next->next->next); // !
	print_linked_list();	
	
	printf("===============\n");
	
	delete_node(first); // Hi
	print_linked_list();	

	return 0;
}

// week15 실습
/*
[W15] Problem 1 - MYFLOAT
100점
MYFLOAT is a structure for maintaining floating numbers. It has two members, int_part and dec_part. int_part is for the integer part of a floating number, and dec_part is for the decimal part. For example, when the user wants to store 123.456, int_part and dec_part are set as 123 and 456, respectively.
Complete init and print functions.
init: Initialize a MYFLOAT variable by receiving values of int_part and dec_part.
print: Print a MYFLOAT variable. (Check the below examples.)
CHECK:
Zeroes should NOT be printed out at the end of dec_part.
ASSUMPTION:
User inputs are not negative numbers and in the int range.
*/
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





// [Review][W15] Problem 2 - Count Alphabets
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ALPHABETS 26
#define MAX_INPUT 100

typedef struct _alphabet {
	char c;
	int count;
} ALPHABET;

ALPHABET* GetAlphabets() {
	ALPHABET *alphabet = (ALPHABET*) malloc(sizeof(ALPHABET) * NUM_ALPHABETS);
	for (int i = 0; i < NUM_ALPHABETS; i++) {
		alphabet[i].c = 'a' + i;
		alphabet[i].count = 0;
	}
	return alphabet;
}

void PrintCount(const ALPHABET* alphabet)
{
	for(int i=0; i<NUM_ALPHABETS; i++)
		printf("%c:%d\n", alphabet[i].c, alphabet[i].count);
}

void CountLetters(const char* text, ALPHABET* alphabet)
{
	for(int i=0; i<strlen(text); i++){
		if(text[i] >= 'a' && text[i] <= 'z'){
			alphabet[text[i] - 'a'].count++;
		}
	}


	
}


int main()
{
	ALPHABET* alphabet = GetAlphabets();
	char* input = (char*) malloc(sizeof(char) * MAX_INPUT);
	printf("Enter a sentence: ");
	fgets(input, MAX_INPUT, stdin);
	if(input[strlen(input)-1] == '\n') input[strlen(input)-1] = '\0';
	
	printf("You entered \"%s\"\n", input);
	
	CountLetters(input, alphabet);
	PrintCount(alphabet);
	
	return 0;
}

// [Review][W15] Problem 3 - AddFirst for a Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node * next;  
} NODE;

NODE* first;

void AddFirst(int val){

	NODE* new_node = (NODE*) malloc(sizeof(NODE));
	new_node->value = val;
	new_node->next = first; //null
	first = new_node;
}

void PrintList()
{
	NODE *curr = first;
	int count=0;
	while(curr != NULL) {
		printf("%d: Value of current node: %d\n", ++count, curr->value);
		curr = curr->next;
	}
}

int main()
{
	for(int i=0; i<10; i++)
		AddFirst(i);
	
	PrintList();
}