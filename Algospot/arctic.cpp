#include <iostream>
#include <list>
#include <tuple>
#include <math.h>
using namespace std;

typedef tuple<double, double> point;

list<point> bases;
list<point> pool;

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
	double thislen;
	double minlen = sqrt(2*1000*1000)+1;
	double output = 0;
	list<point>::iterator pi;
	list<point>::iterator bi;
	list<point>::iterator mini;
	
	pool.push_back(*bases.begin());
	bases.erase(bases.begin()); // move head base in pool
	while(bases.size() != 0){
		minlen = sqrt(2*1000*1000)+1;
		for(pi = pool.begin(); pi!=pool.end(); pi++){
			for(bi = bases.begin(); bi!=bases.end(); bi++){
				thislen = calc_len(*pi, *bi);
				if (thislen < output || isSame(thislen, output)){
					minlen = thislen;
					pool.push_back(*bi);
					bi = bases.erase(bi);
					bi--;

				}
				else if(thislen < minlen){
					minlen = thislen;
					mini = bi;
				}
			}
			
		}
		if ( minlen > output ){
			output = minlen;
			pool.push_back(*mini);
			bases.erase(mini);
		}
	}
	return output;
	
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

