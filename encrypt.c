#include <stdio.h>
#include <string.h>
int main(void){
	int a=0;
	int i=0;
	int j=0;
	char str[101];
	char after[101];
	scanf("%d",&a);
	while(a>0){
		memset(str,0,sizeof(str));
		memset(after,0, sizeof(after));
		i=0;j=0;
		scanf("%s",str);
		while(str[i]!='\0'){
			after[j]=str[i];
			i+=2;
			j+=1;}
		i=1;
		while(str[i]!='\0'){
			after[j]=str[i];
			i+=2;
			j+=1;
		}
		//after[j]='\0';
		printf("%s\n",after);
		
		a--;
	}
}
