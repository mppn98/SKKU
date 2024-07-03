#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 100000


int findSavedStrength(char* food);
int largelen(char* s);
int main() {
	char *food = (char *)malloc(MAX_LENGTH * sizeof(char));
	
	if (food == NULL) {
		printf("Failed to allocate memory.\n");
		return 1;
	}
	
	printf("Enter Food: ");
	scanf("%s", food);
	
	printf("Saved Strength is: %d\n", findSavedStrength(food));
	
	free(food);
	
	return 0;
}



int findSavedStrength(char* food){

	int savedStrength=largelen(food);
	return (savedStrength*100)/2;

}
int largelen(char* str) {
		int odd=0;
    int sym = 0;
	
    int chararray[128] = { 0 };
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        chararray[str[i]]++;
    }
    for (int j = 0; j < 128; j++) {
        sym += chararray[j] / 2;
        if (chararray[j] % 2 == 1) {
            odd = 1;
        }
    }
    return (sym * 2) + odd;
}