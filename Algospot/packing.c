#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int * vol;
int * happy;
int count = 0;
int goods, capicity;
char names[100][21];
char packed[100] = {0, };
int cache[100][1000] = {-1, };

int packing(int index, int this_cap){
	if (index == goods)
		return 0;
	if (cache[index][this_cap] != -1){
		return cache[index][this_cap];
	}
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
	cache[index][this_cap] = this_max;
	return this_max;
	
}

void get_names(int index, int this_cap){
	if (index == goods){
		return;
	}
	if (packing(index, this_cap) == packing(index+1, this_cap)){			
		get_names(index+1, this_cap);			
	}
	else{
		packed[index] = 1;
		count++;
		get_names(index+1, this_cap - vol[index]);
	}
	
	
}
void cache_reset(){
	int i,j;
	for(i=0; i<100; i++){
		for(j=0; j<1000; j++){
			cache[i][j]= -1;
		}
	}
}
int main(){
	int i, j, k, a, test, ans;

	scanf("%d", &test);
	for(a=0; a<test; a++){
		count = 0;
		memset(packed, 0, 100);			
		cache_reset();	
		scanf("%d %d", &goods, &capicity);
		vol = (int*)malloc(goods * sizeof(int));
		happy = (int*)malloc(goods * sizeof(int));
		for(i=0; i<goods; i++){
			scanf("%s %d %d", &names[i][0], &vol[i], &happy[i]);
			
		}
		ans = packing(0, capicity);
		get_names(0, capicity);
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
