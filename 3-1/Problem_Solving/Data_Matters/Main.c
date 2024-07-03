#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n1;
int n2;



// 이진 탐색 검색함수
int binarySearch(char** strArr1, char** strArr2) {
	int count = 0;

	for (int i = 0; i < n1; i++) {
		int low = 0;
		int high = n2 - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			int cmp = strcmp(strArr1[i], strArr2[mid]);
			if (cmp == 0) {
				count++;
				break;
			}
			else if (cmp < 0) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}

	return count;
}

// 선형 검색함수
int linearSearch(char** strArr1, char** strArr2) {
	int count = 0;
	int i = 0, j = 0;

	while (i < n1 && j < n2) {
		int cmp = strcmp(strArr1[i], strArr2[j]);
		if (cmp == 0) {
			count++;
			i++;
			j++;
		}
		else if (cmp < 0) {
			i++;
		}
		else {
			j++;
		}
	}

	return count;
}
int countCommonStrings(char** strArr1, char** strArr2) {
	// n1과 n2 중 더 큰 값과 작은 값을 찾아 비율 계산
	int max = n1 > n2 ? n1 : n2;
	int min = n1 < n2 ? n1 : n2;

	if (max / min >= 10) { // 10배 이상 차이나면 이진 탐색 사용
		//10배인 이유는 보고서에 작성하였습니다.
		return binarySearch(strArr1, strArr2);
	}
	else { // 그렇지 않은 경우 선형 탐색 
		return linearSearch(strArr1, strArr2);
	}
}

int main()
{
  scanf("%d", &n1);
  scanf("%d", &n2);
  char** strArr1 = (char**) malloc(sizeof(char*)*n1);
  char** strArr2 = (char**) malloc(sizeof(char*)*n2);
    
  for(int i=0; i<n1; i++)
    strArr1[i] = (char*) malloc(sizeof(char)*9);
  for(int i=0; i<n2; i++)
    strArr2[i] = (char*) malloc(sizeof(char)*9);

  for(int i=0; i<n1; i++)
    scanf("%s", *(strArr1 + i));
  for(int i=0; i<n2; i++)
    scanf("%s", *(strArr2 + i));
 
  int sum = 0;
  int test_num = 150;
  for(int i=0; i<test_num; i++)
    sum+=countCommonStrings(strArr1, strArr2);
  printf("%d\n", sum/test_num);

  free(strArr1);
  free(strArr2);

  return 0;
}