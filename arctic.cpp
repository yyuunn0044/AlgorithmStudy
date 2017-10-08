#include <iostream>
#include <list>
#include <tuple>
#include <math.h>
using namespace std;

typedef tuple<double, double> point;
double basex[100];
double basey[100]; 
double minlength[100];
bool inPool[100];
list<point> bases;
list<point> pool;
//TODO comparison of two double

double calc_len(point a, point b){
	double sum = pow((get<0>(a)-get<0>(b)), 2.0) + pow((get<1>(a)-get<1>(b)), 2.0);
	return sqrt(sum);
}
bool isSame(double a, double b){
	double diff = a-b;
	if (fabs(diff) <= (1.0e-8))
		return 1;
	else
		return 0;
}
double min_output_calc(int base_num){
	int i, j;
	double thislen;
	double minlen = sqrt(2*1000*1000)+1;
	double output = 0;
	list<point>::iterator itr;
	list<point>::iterator pi;
	list<point>::iterator bi;
	list<point>::iterator mini;
	
	pool.push_back(*bases.begin());
	bases.erase(bases.begin()); // move head base in pool
	while(bases.size() != 0){
		printf("pool: %d bases: %d\n", pool.size(), bases.size());
		minlen = sqrt(2*1000*1000)+1;
		for(pi = pool.begin(); pi!=pool.end(); pi++){
			printf("pool point: %lf %lf\n", get<0>(*pi), get<1>(*pi));
			for(bi = bases.begin(); bi!=bases.end(); bi++){
				thislen = calc_len(*pi, *bi);
				if (thislen < output || isSame(thislen, output)){
					printf("i got it\n");
					minlen = thislen;
					pool.push_back(*bi);
					bi = bases.erase(bi);
					bi--;

				}
				else if(thislen < minlen){
					printf("save minlen, minlen %lf thislen %f\n", minlen, thislen);
					minlen = thislen;
					mini = bi;
				}
				else printf("do nothing\n");
			}

			
		}
		if ( minlen > output ){
			output = minlen;
			pool.push_back(*mini);
			bases.erase(mini);
		}
		printf("end of output: %lf\n", output);
//		itr = bases.begin();
	}
	return minlen;
	
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
	double x_cdn, y_cdn;
	int base_num;
	tuple<double, double> tmp;
	scanf("%d", &testcase);
	for(a=0; a<testcase; a++){
		bases.clear();
		pool.clear();
		scanf("%d", &base_num);
		for(i=0; i<base_num; i++){
			scanf("%lf %lf", &x_cdn, &y_cdn);
			tmp = make_tuple(x_cdn, y_cdn);
			bases.push_back(tmp);
		}
		ans = min_output_calc(base_num);
		printf("%.2lf\n", ans);
	}
	return 0 ;
}

