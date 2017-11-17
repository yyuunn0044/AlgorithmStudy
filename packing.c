#include <stdio.h>
int * vol;
int * happy;
int count = 0;
int goods, capicity;
char packed[100] = {0, };
char names[100][21] = {NULL, };
int packing(int index, int this_cap){
	if (index == goods)
		return 0;
	int ans1 = -1;
	int ans2 = -1;
	int this_max;
	ans2 = packing(index+1, this_cap);
	this_max = ans2;
	
	if (vol[index] <= this_cap){
		ans1 = packing(index+1, this_cap-vol[index])+ happy[index];
		if (ans1 > this_max){
			this_max = ans1;
		}
	}
	return this_max;
	
}

void printf_names(int index, int this_cap){
	if (index == goods){
		return;
	}

	if (packing(index, this_cap) == packing(index+1, this_cap)){			
		printf_names(index+1, this_cap);			
	}
	else{
		packed[index] = 1;
		count++;
		printf_names(index+1, this_cap - vol[index]);
	}
	
	
}
int main(){
	int i, j, k, a, test, ans;

	scanf("%d", &test);
	for(a=0; a<test; a++){
		count = 0;
		memset(packed, 0, sizeof(char)*100);			
		scanf("%d %d", &goods, &capicity);
		vol = malloc(goods * sizeof(int));
		happy = malloc(goods * sizeof(int));
		for(i=0; i<goods; i++){
			scanf("%s %d %d", &names[i][0], &vol[i], &happy[i]);
			
		}
		ans = packing(0, capicity);
		printf_names(0, capicity);
		printf("%d %d\n", ans, count);

		for(i=0; i<goods; i++){
			if (packed[i] == 1){
				printf("%s\n", names[i]);
			}
		}

		free(vol);
		free(happy);
		
	}
}
