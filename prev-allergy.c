#include <stdio.h>
#include <stdlib.h>

int eat[50][50] = {0, };
int index[50]={0,};
int same[50]={0,};
int foods, friends;
int count;
void find_first_food(int name){
	int i = index[name];
	while(i<foods){
		if (eat[name][i] == 1){
			index[name] = i;
			break;
		}
	}
}
void check_other_eats(int name){
	int i;
	int food = index[name];
	for(i=name; i<friends ; i++){
		if (eat[i][food] == 1){
			index[i] = food;
			same[i] = 1;
			count -= 1;
		}
	}
}

int check_all_eats(){
	int i, j;
	for(i = 0; i<friends; i++){
		if (eat[i][index[i]] == 0)
			return 0;
	}
	return 1;

} 

int move_index(){
	int i = friends;
	for(; i>=0; i--){
		if (same[i] == 0)
			break;
	}
	while(1){
		if (index[i] == foods - 1){
			if (i == friends -1 )
				return 0;
			index[i] = 0;
			i--;
		}
		else{
			index[i] += 1;
		}
	}
	return 1;
}
int main() {
	int N;
	int* data = NULL;
	int i, j,k,  testcase, a;
	
	char* names[50] = {NULL, };
	int success;
	int num;
	int min = 80;
	char* tmp = malloc(11);
	scanf("%d\n", &testcase);
	for(a=0; a<testcase; a++){
		memset(index, 0, 50);
		memset(same, 0, 50);
		scanf("%d %d\n", &friends, &foods);
		for(i=0; i<friends; i++){
			names[i] = malloc(11);
			scanf("%s", names[i]);
		}
		for(i=0; i<foods; i++){
			scanf("%d", &num);
			for(j=0; j<num; j++){
				scanf("%s", tmp);
				for(k=0; k<friends; k++){
					if (strcmp(tmp, names[k]) == 0){
						eat[k][i] = 1;
					}
				}
			}
		}
		for(i=0; i<friends; i++){
			printf("%s ", names[i]);
		}
		printf("\n");
		for(i=0; i<friends; i++){
			for(j=0; j<foods; j++){
				printf("%d", eat[i][j]);
				
			}
			printf("\n");
		}
		count = foods;
		while(index[0]<foods){
			for (i=0; i<friends; i++){
				if (eat[i][index[i]] == 0){
					find_first_food(i);
					check_other_eats(i);
				}
				success = check_all_eats();	
				if (success == 1){
					if (count < min){
						min = count;
						
					}
					count = foods;
					break;
				}
			}
			if (!move_index()){
				break;
			}
			memset(same, 0, 50);
		}
		
		printf("%d\n", count);
		
		
	}
	for(i=0; i<50; i++){
		if (names[i] != NULL){
			free(names[i]);
		}
	}
	free(tmp);
	return 0;
}
