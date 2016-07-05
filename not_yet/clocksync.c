#include <stdio.h>
#include <string.h>

int check(int *state){
	int i=0;
	for(i=0;i<16;i++){
		if (state[i]!=12)
			return 0;
	}
	return 1;
}


int find(int *state, const char link[10][16], int sw){
	int state1[16]={0};
	int state2[16]={0};
	int state3[16]={0};
	int num=0;
	int i=0;
	int j=0;
	
	if( sw==9 ){
		for(;j<16;j++)
			printf("%d ",state[j]);
		printf("9!!!\n");
	}
	if( sw==8 ){
		for(;j<16;j++)
			printf("%d ",state[j]);
		printf("8!!\n");
	}
/*	if( sw==7 )
		for(;j<16;j++)
			printf("%d ",state[j]);
	if( sw==6 )
		for(;j<16;j++)
			printf("%d ",state[j]);
	if( sw==5 )
		for(;j<16;j++)
			printf("%d ",state[j]);
*/	
	
	
	
	if (check(state)==1)
		return 1;
	if (sw<0)
		return 0;
	
	num+=find(state, link, sw-1);
	memcpy(state1, state, 16);
	for (i=0; i<16; i++){
		state1[i]+=link[sw][i]*3;
		if (state1[i]==15)
			state1[i]=3;
	}
	num+=find(state1, link, sw-1);
	memcpy(state2, state1, 16);
	for (i=0; i<16; i++){
		state2[i]+=link[sw][i]*3;
		if (state2[i]==15)
			state2[i]=3;
	}
	num+=find(state2, link, sw-1);
	memcpy(state3, state2, 16);
	for (i=0; i<16; i++){
		state3[i]+=link[sw][i]*3;
		if (state3[i]==15)
			state3[i]=3;
	}
	num+=find(state3, link, sw-1);
/*	for(j=0; j<16; j++)
		printf("%d ", state[j]);
	printf("\n");*/
	return num;

}




int main(void){
	int a=0;
	int i=0;
	int ans=0;
	int state[16]={0};
	const char link[10][16]={{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
		                {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
		                {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
		                {1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
		                {0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
		                {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
		                {0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
		                {0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
		                {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
		                {0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}};
	scanf("%d", &a);
	while(a>0){
		memset(state, 0, sizeof(state));
		for(i=0; i<16; i++){
			scanf("%d",&state[i]);
		}
		ans=find(state, link,9);	
		printf("%d\n", ans);
		a--;
	}
}

	
