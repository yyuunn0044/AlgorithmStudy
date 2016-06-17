#include <stdio.h>

int main(void){
	int a=0;
	int all=0;
	int win=0;
	int i=0;
	int ratio=0;
	double dratio=0;
	int new=0;
	scanf("%d", &a);
	while(a>0){
		i=0;
		scanf("%d %d", &all, &win);
		dratio=100*((double)win/all);
		ratio=(int)dratio;
		new=ratio;

		while(1){
			if (i>2000000000)
				break;
			win+=100000;
			all+=100000;
			i+=100000;
			dratio=100*((double)win/all);
			new=(int)dratio;
			if((new-ratio)!=0)
				break;
		}
		win-=100000;
		all-=100000;
		i-=100000;

		while(1){
			if (i>2000000000)
				break;
			win+=1;
			all+=1;
			i+=1;
			dratio=100*((double)win/all);
			new=(int)dratio;
			if ((new-ratio)!=0)
				break; 
		}
		
		if (i>2000000000)
			printf("%d\n",-1);
		else
			printf("%d\n",i);
		a--;
	}
}

	
