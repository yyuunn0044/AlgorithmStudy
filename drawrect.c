#include<stdio.h>

int main(void){
	int num;
	int i=0;
	int nums[3][2];
	int after[2];
	int a=0;
	scanf("%d",&a);
	while(a>0){

		for(i=0;i<3;i++){
			scanf("%d %d",&nums[i][0], &nums[i][1]);
		}
		if(nums[0][0]==nums[1][0])			
			after[0]=nums[2][0];
		else if(nums[0][0]==nums[2][0])
			after[0]=nums[1][0];
		else if(nums[1][0]==nums[2][0])
			after[0]=nums[0][0];
		if(nums[0][1]==nums[1][1])			
			after[1]=nums[2][1];
		else if(nums[0][1]==nums[2][1])
			after[1]=nums[1][1];
		else if(nums[1][1]==nums[2][1])
			after[1]=nums[0][1];
		printf("%d %d\n", after[0], after[1]);
		
		a--;
	}
}



