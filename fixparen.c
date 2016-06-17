#include <stdio.h>
#include <string.h>

int oppo(int a){
	if (a==40)
		return 41;
	else if (a==41)
		return 40;
	else if (a==123)
		return 125;
	else if (a==125)
		return 123;
	else if (a==91)
		return 93;
	else if (a==93)
		return 91;
	else if (a==60)
		return 62;
	else if (a==62)
		return 60;
	else {
		return 0;
	}
}
	

int isbig(char a, char b, char *order){
	int j=0;
	int num=0;


	while(order[j]!=a)
		j++;

	num=j;
	j=0;
	while(oppo(order[j])!=b)
		j++;

	if (num>j)
		return 1;
	else if (num==j)
		return 0;
	if (num<j)
		return -1;
	
}


int main(void){
	int a=0;
	int i=0;
	int top=0;
	int big=0;
	char arr[101];
	char order[5];
	char check[101];
	int nums[101];
	scanf("%d", &a);
	while(a>0){
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));
		memset(nums, 0, sizeof(nums));
		scanf("%s",arr);
		scanf("%s",order);
		for(i=0; arr[i]!='\0'; i++){
			if (arr[i]==40 || arr[i]==123 || arr[i]==91 || arr[i]==60){
				check[top]=arr[i];
				nums[top]=i;
				top++;
				continue;
			}
			else{
				if(check[top-1]==oppo(arr[i])){
					check[top-1]='\0';
					nums[top-1]='\0';
					top--;
					continue;
				}
				else{
					big=isbig(check[top-1], arr[i], order);
					if(big<0){
						arr[i]=oppo(check[top-1]);
						check[top-1]='\0';
						nums[top-1]='\0';
						top--;
						continue;
					}
					if(big>0){
						arr[nums[top-1]]=oppo(arr[i]);
						check[top-1]='\0';
						nums[top-1]='\0';
						top--;
						continue;
					}
				}
			}
		}
		printf("%s\n", arr);	
		a--;
	}
}
