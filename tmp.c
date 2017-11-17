#include <stdio.h>
#include <stdlib.h>
int kinds, budget;
int price[20];
int point[20];

int get_lcm(){
	int i;
	int this_lcm = price[0];
	int gcd;
	int a, b, tmp;
	for(i=1; i<kinds; i++){
		while(1){
			if (this_lcm > price[i]){
				a = this_lcm;
				b = price[i];
			}
			else{
				a = price[i];
				b = this_lcm; 
			}
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
	printf("lcm: %d", this_lcm);
	return this_lcm;
}

int sushi(int index, int budget){
	int max, tmp;
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
	printf("start");
	for(a=0; a<test; a++){
		max_unit_price = -1;
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
			printf("b: %d t: %d", budget, total_point);
		}
		total_point += sushi(0, budget);
		printf("%d\n", ans);
	}
	
	return 0;
}
