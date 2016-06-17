#include <stdio.h>
#include <string.h>
int main(void){
	int a=0;
	int i=0;
	int goal=0;
	int all[9];
	int total=0;
	scanf("%d", &a);
	while(a>0){
		total=0;
		memset(all, 0, sizeof(all));
		scanf("%d", &goal);
		scanf("%d %d %d %d %d %d %d %d %d", &all[0], &all[1], &all[2], &all[3], &all[4], &all[5], &all[6], &all[7], &all[8]);
		for(i=0;i<9;i++)
			total+=all[i];
		if (total<=goal)
			printf("YES\n");
		else if(total>goal)
			printf("NO\n");
	
		a--;
	}
}

	
