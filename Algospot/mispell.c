#include <stdio.h>
#include <string.h>
int main(void){
	int a=0;
	int i=0;
	int num=0;
	int order=1;
	char str[81];
	char after[81];
	scanf("%d", &a);
	while(a>0){
		memset(str, 0, sizeof(str));
		memset(after, 0, sizeof(after));
		scanf("%d %s", &num, str);
		for(i=0;i<num-1;i++){
			after[i]=str[i];
		}
		i++;
		for(;str[i]!='\0';i++){
			after[i-1]=str[i];
		}
		after[i-1]='\0';
		printf("%d %s\n", order, after);
		order++;
		a--;
	}
}

	
