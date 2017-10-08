#include <stdio.h>
#include <math.h>

double basex[100];
double basey[100]; 
double minlength[100];

double min_output_calc(int base_num){
	int i, j;
	double thislen;
	double maxlength=0.0;
	for(i=0; i<base_num; i++){
		for(j=0; j<base_num; j++){
			if (i==j)
				continue;
			thislen =  pow((basex[i]-basex[j]), 2.0)+  pow((basey[i]-basey[j]), 2.0);
			if ( minlength[i] > thislen ){
				minlength[i] = thislen;
			}
		}
	}
	for(i=0; i<base_num; i++){
		if ( maxlength < minlength[i] ){
			maxlength = minlength[i];
		}
	}
	return sqrt(maxlength);
	
}
void reset_minlength(){
	int i=0;
	for(i=0; i<100; i++){
		minlength[i] = 2*1000*1000;
	}
}
int main(){
	int testcase, a, i, j, k;
	double ans;
	int base_num;
	scanf("%d", &testcase);
	for(a=0; a<testcase; a++){
		scanf("%d", &base_num);
		for(i=0; i<base_num; i++){
			scanf("%lf %lf", &basex[i], &basey[i]);
	//		base2x[i] = base1x[i];
	//		base2y[i] = base1y[i];
		}
		reset_minlength();
		ans = min_output_calc(base_num);
	//	pow(ans, 2);
		printf("%.2lf\n", ans);
	}
	return 0 ;
}

