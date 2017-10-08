#include <stdio.h>

int left[46];
int right[46];
int friends;

int redundancy_check(long long selected){
	int index;
	int arr[10] = {0,};
	while(selected != 0){
		index = selected % 100;
		if (arr[left[index]] != 0 || arr[right[index]] != 0 ){
			return 1;
		}
		arr[left[index]] = 1;
		arr[right[index]] = 1;
		selected = selected / 100;
	}
	return 0;
}
int picnic(int start, int select_num, long long selected){
//	printf("picnic: start %d select_num %d seleted %lld\n", start, select_num, selected);
	int i=0, sum=0;
	if ( redundancy_check(selected) == 1 ){
		return 0;
	}
	if ( select_num == 0 ){
//		printf("select num is 0,,,selected: %lld\n", selected);
//		if (redundancy_check(selected) == 0){
			return 1;
	//	}
	//	return 0;
	}
	for(i=start; i<(friends-select_num+2); i++){
		sum += picnic(i+1, select_num-1, selected*100+i);
	}
	return sum;
}
int main(){
	int testcase, a, i, j, k, ans;
	int students;
	scanf("%d", &testcase);
	for(a=0; a<testcase; a++){
		scanf("%d %d", &students, &friends);
		for(i=1; i<friends+1; i++){
			scanf("%d %d", &left[i], &right[i]);
		}
		ans = picnic(1, students/2, 0);
		printf("%d\n", ans);
	}
}
