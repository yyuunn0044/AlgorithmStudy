#include <stdio.h>

int presum;
int arr[100000];
//int new[100000];
int num;


int sum(int *arr, int i){
	presum+=arr[i];
	printf("pre: %d\n",presum);
	return presum;
}





void printarr(int * arr){
	int i=0;
	while(arr[i]!=NULL){
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int main(void){
	int a=0;
	scanf("%d", &a);
	while(a>0){
		int i=0;
		presum=0;
		memset(arr, NULL, sizeof(arr));
		memset(new, NULL, sizeof(new));
		scanf("%d", &num);
		for(;i<num;i++){
			scanf("%d", &arr[i]);
		}
		arr[num]=NULL;
		
		while(i>=0){
			if (sum(arr, i)<0){
				arr[i]=NULL;
				num=strlen(arr);
				printf("len: %d\n", num);
				presum=0;
				i=num-1;
				continue;
			}
			i--;
		}
		printf("first num: %d\n", num);
		for(i=0; i<num; i++){
			new[num-i-1]=arr[i];
			printf("i: %d\n", i);
		}
		printf("hoho");
	
		new[num]=NULL;
		
//		strncpy(arr, new, num);
		
		
		
		printarr(new);
		printarr(arr);	

		presum=0;
		printf("scnd\n");
		while(i>=0){
			if (sum(new, i)<0){
				new[i]=NULL;
				num=strlen(new);
				presum=0;
				i=num-1;
				continue;
			}
			i--;
		}
		presum=0;
		i=num-1;
		printf("last\n");
		while(i>=0){
			sum(new, i);
			i--;
		}
		printf("%d\n",presum);

	
		a--;
	}
}

	
