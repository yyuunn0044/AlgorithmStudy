#include <stdio.h>
#include <stdlib.h>
int kinds, budget;
int price[20];
int point[20];
int cache[20][10000];
int get_lcm(){
	int i;
	int this_lcm = price[0];
	int gcd;
	int a, b, tmp;
	for(i=1; i<kinds; i++){
		if (this_lcm > price[i]){
			a = this_lcm;
			b = price[i];
		}
		else{
			a = price[i];
			b = this_lcm; 
		}
		while(1){
	
			if (a % b == 0){
				gcd = b;
				break;
			}
			tmp = a;
			a = b;
			b = tmp % b; 
		}
		
		this_lcm = (price[i]*this_lcm)/gcd;
	}
	return this_lcm;
}

int sushi(int index, int budget){
	int max, tmp;
	int budget_num = (budget / 100);
	if (budget_num < 10000){
		if (cache[index][budget_num] != -1){
			return cache[index][budget_num];
		}
	}
	if (budget <= 0 || index == kinds){
		return 0;
	}
	max = sushi(index+1, budget);
	if ( budget >= price[index]){
		tmp = sushi(index, budget-price[index])+point[index];
		if (tmp > max){
			max = tmp;
		}
	}
	if (budget_num < 10000){
		cache[index][budget_num] = max;
	}
		return max;
}

int main() {
	int N;
	int* data = NULL;
	int a, i, j,k, test, ans;
	int tmp;
	int max_unit_price, max_unit_point;
	int total_point;
	scanf("%d", &test);
	for(a=0; a<test; a++){
		for(i=0; i<20; i++){
			for(j=0; j<10000; j++){
				cache[i][j] = -1;
			}
		}
		max_unit_point = -1;
		total_point = 0;
		scanf("%d %d", &kinds, &budget);
		for(i=0; i<kinds; i++){
			scanf("%d %d", &price[i], &point[i]);
		}
		max_unit_price = get_lcm();
		for(i=0; i<kinds; i++){
			tmp = (max_unit_price / price[i]) * point[i];
			if ( tmp > max_unit_point){
				max_unit_point = tmp;
			}
		}
		while(budget >= max_unit_price){
			budget -= max_unit_price;
			total_point += max_unit_point;
		}
		total_point += sushi(0, budget);
		printf("%d\n", total_point);
	}
	
	return 0;
}
