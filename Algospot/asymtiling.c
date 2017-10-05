#include <stdio.h>

int count_cases(int prefix, int len);

int main(){
	int i;
	int testcase, ans;
	int length;
	scanf("%d", &testcase);
	for(i=0; i<testcase; i++){
		scanf("%d", &length);
		ans = count_cases(0, length);
		printf("%d\n", ans);
	}
}

int count_cases(int prefix, int len){
	int ans;
	int case
	if (len >= 3){
		count_cases(prefix*10+1, len-1) + count_cases(prefix*10+2, len-2);
	}
	else if (len == 2){
		
	}
	else if (len == 1){
	
	}
	else{
		printf("wrong1\n");
	}

}

int check_palindrome(int str){

}
