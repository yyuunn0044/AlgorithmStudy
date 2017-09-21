#include <stdio.h>

long long L=2000000000;

int ratio(long long b, long long a){
	return (a*100)/b;
}

int find(long long games, long long won){
	long long lo=0;
	long long hi=L;
	if (ratio(games, won)==ratio(games+L, won+L))
		return -1;
	while(lo+1<hi){
		long long mid = (lo+hi)/2;
		if(ratio(games, won)==ratio(games+mid, won+mid))
			lo=mid;
		else
			hi=mid;
	}
	return hi;
}

int main(void){
	int a=0;
	int games=0;
	int won=0;
	int ans=0;
	scanf("%d",&a);
	while(a>0){
		scanf("%d %d", &games, &won);
		ans=find(games, won);
		printf("%d\n",ans);
		a--;
	}
}
	
	
