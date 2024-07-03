#include <stdio.h>
#include <stdlib.h>
/* You cannot add other libraries */
void print_mountain_info(const int** mountain, int mountain_size);
const int** alloc_and_init_mountain(int mountain_size);

int Herb(const int** mountain, int mountain_size) {
		int* pre = (int*)malloc(mountain_size * sizeof(int));
		int* cur = (int*)malloc(mountain_size * sizeof(int));
	
    pre[0] = mountain[0][0];
    
    for (int i = 1; i < mountain_size; i++) {
        cur[0] = pre[0] + mountain[i][0];
        cur[i] = pre[i-1] + mountain[i][i];
        
        for (int j = 1; j < i; j++) {
            cur[j] = mountain[i][j] + (pre[j-1] > pre[j] ? pre[j-1] : pre[j]);
        }

        int* temp = pre;
        pre = cur;
        cur = temp;
    }
    
    int maxHerbs = 0;
    for (int i = 0; i < mountain_size; i++) {
        if (pre[i] > maxHerbs) {
            maxHerbs = pre[i];
        }
    }
    
    free(pre);
    free(cur);
    
    return maxHerbs;
}
void print_mountain_info(const int** mountain, int mountain_size)
{
    for(int i = 0; i < mountain_size; i++){
        for(int j = 0; j < i + 1; j++){
            printf("%d", mountain[i][j]);
            if(j == i) printf("\n");
            else printf(" ");
        }
        
    }
}

const int** alloc_and_init_mountain(int mountain_size)
{
	int **mountain_org;
	mountain_org = (int**)malloc(sizeof(int*) * mountain_size);
  for(int i = 0; i < mountain_size; i++){
  	mountain_org[i] = (int*)malloc(sizeof(int) * (i + 1));
  }
  srand(mountain_size);
  for(int i = 0; i < mountain_size; i++){
  	for(int j = 0; j < i + 1; j++){
    	mountain_org[i][j] = (int)(rand() % 9999 + 1);
  	}
  }
	return (const int **)mountain_org;
}
/* Write your code */
/*								 */
int main()
{
  int mountain_size= 0;
		
  scanf("%d", &mountain_size);
				
		
	 
	const int** mountain = alloc_and_init_mountain(mountain_size);

		//print_mountain_info(mountain, mountain_size);
			
	int maxcount = Herb(mountain, mountain_size);
  printf("%d\n", maxcount);
	
	 for(int i = 0; i < mountain_size; i++) {
        free((void*)mountain[i]);
    }
    free((void*)mountain);

}