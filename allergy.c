#include <stdio.h>
#include <string.h>
int friends, foods;
char friend_names[50][11];
int eats[50][50];
int canEat[50];
int best_chosen;

void best(int first, int chosen){
	int i, j;
	if (chosen>best_chosen)
		return;
	if (first == friends){
		if (chosen<best_chosen)
			best_chosen = chosen;
			return;
	}
	if (canEat[first] >= 1){
		best(first+1, chosen);
	}
	else{
		for(i=0; i<foods; i++){
			if (eats[first][i] == 1){
				for(j=first; j<friends; j++){
					if (eats[j][i] == 1){
						canEat[j] += 1;
					}
				}
				best(first+1, chosen+1);
				for(j=first; j<friends; j++){
					if (eats[j][i] == 1){
						canEat[j] -= 1;
					}
				}
			}
	
		}
		
	}
}



int main(){
	int i, j, k, a, test, tmp_int, ans;
	char tmp_name[11];
	scanf("%d", &test);
	for(a=0; a<test; a++){
		best_chosen = 51;
		for(i=0; i<50; i++){
			for(j=0; j<50; j++){
				eats[i][j] = 0;
			}
		}
		for(i=0; i<50; i++){
			canEat[i] = 0;
		}
		scanf("%d %d", &friends, &foods);
		for(i=0; i<friends; i++){
			scanf("%s", &friend_names[i][0]);
		}
		for(i=0; i<foods; i++){
			scanf("%d", &tmp_int);
			for(j=0; j<tmp_int; j++){
				scanf("%s", tmp_name);
				for(k=0; k<friends; k++){
					if (strcmp(&friend_names[k][0], tmp_name) == 0){
						eats[k][i] = 1;
					}
				}
			}
		}
		// ------------for input end -----------
		best(0, 0);
		printf("%d\n", best_chosen);
	}
}
