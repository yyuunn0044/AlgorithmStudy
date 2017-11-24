#include <stdio.h>
int kinds, budget;
int price[20];
int point[20];
int best[201];
int max(int a, int b){
	return a>b?a:b;
}
void sushi(){
	int i,j;
	for(i=0; i<kinds; i++){
		best[price[i]] = point[i];
	}
	for(i=1; i<=budget; i++){
		best[i%201] = 0;
		for(j=0; j<kinds; j++){
			if (i>=price[j]){
				best[i%201] = max(best[i%201], best[(i-price[j])%201]+point[j]);
			}
		}
		
	}
	
}
int main(){
	int i,j,k,a,test,ans;
	scanf("%d", &test);

	for(a=0; a<test; a++){
	scanf("%d %d", &kinds, &budget);
	for(i=0; i<kinds; i++){
		scanf("%d %d", &price[i], &point[i]);
	}
	for(i=0; i<kinds; i++){
		price[i] = price[i]/100;
	}
	budget = budget/100;
	sushi();
	printf("%d\n", best[budget%201]);
	}
}
