#include <stdio.h>
#include <string.h>
int main(void){
	int a=0;
	int i=1;
	double amount=0;
	char kg[3]="kg";
	char l[2]="l";
	char lb[3]="lb";
	char g[2]="g";
	char unit[3];
	scanf("%d", &a);
	while(a>0){
		memset(unit, 0, sizeof(unit));
		scanf("%lf %s", &amount, unit);
		if (strcmp(unit, kg)==0){
			printf("%d %.4f lb\n", i, 2.2046*amount);
		}
		else if(strcmp(unit, lb)==0)
			printf("%d %.4f kg\n", i, 0.4536*amount);
		else if(strcmp(unit, l)==0)
			printf("%d %.4f g\n", i, 0.2642*amount);
		else if (strcmp(unit, g)==0)
			printf("%d %.4f l\n", i, 3.7854*amount);
		i++;
		a--;
	}
}

	
