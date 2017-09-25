#include <stdio.h>
#include <stdlib.h>
double calcost(int* arr, int src, int dst){
	int i=0;
	double sum=0;
	double avg=0;
	for(i=src; i<dst+1; i++){
		sum = sum+arr[i];
	}
	avg = sum/(double)(dst-src+1);
	return (double)avg;
}
double samesize_calcost(int* arr, int whole, int min){
	int i;
	int costs = whole-min+1;
	double thiscost;
	double mincost;
	mincost=-1; 
	for(i=0; i<costs; i++){
		thiscost = calcost(arr, i, i+min-1);
		if (mincost == -1 || thiscost<mincost){
			mincost = thiscost;
		}
	}
	return (double)mincost;

}

int main(){
	int testcase, i, j;
	int wholeday, minday;
	int cost[1000];
	double thiscost;
	double mincost;
	scanf("%d", &testcase);
	for(i=0; i<testcase; i++){
		scanf("%d %d", &wholeday, &minday);
		for(j=0; j<wholeday; j++){
			scanf("%d", &cost[j]);
		}

		mincost = samesize_calcost(cost, wholeday, minday);
		minday++;
		for(; minday<=wholeday; minday++){
			thiscost = samesize_calcost(cost, wholeday, minday);
			if (thiscost<mincost){
				mincost = thiscost;
			}
		}
		printf("%.11f\n", mincost);

	}
	return 0;

}


