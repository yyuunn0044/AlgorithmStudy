#include <stdio.h>
#include <string.h>
int main(void){
	int a=0;
	int i=0;
	int top=0;
	int aa=0;
	char arr[10001];
	char check[10001];
	scanf("%d", &a);
	while(a>0){
		memset(arr,0,sizeof(arr));
		memset(check, 0, sizeof(check));
		top=0;
		aa=0;
		scanf("%s",arr);
		for(i=0; arr[i]!='\0'; i++){

			if (arr[i]==40){
				aa=1;
				check[top]=1;
				top++;;
				continue;
			}
			else if (arr[i]==123){
				aa=1;
				check[top]=2;
				top++;
				continue;
			}
			else if (arr[i]==91){
				aa=1;
				check[top]=3;
				top++;
				continue;
			}

			else if (arr[i]==41){
				if(check[top-1]==1){
					check[top-1]='\0';
					top--;
					continue;
				}
				else{
					break;
				}
			}
			else if (arr[i]==125){
				if(check[top-1]==2){
					check[top-1]='\0';
					top--;
					continue;
				}
				else{
					break;
				}
			}

			else if(arr[i]==93){
				if(check[top-1]==3){
					check[top-1]='\0';
					top--;
					continue;
				}
				else{
					break;
				}
			}
		}

		if (i==strlen(arr) && check[0]=='\0'){
			printf("YES\n");
		}
		else
			printf("NO\n");
		/*
		if (check[0]!='\0'){
			printf("NO\n");
		}
		else if (aa==0){
			printf("NO\n");
		}
		else
			printf("YES\n");
	*/
		a--;
	}
}

	
