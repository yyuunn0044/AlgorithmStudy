#include <stdio.h>

unsigned int count_cases(unsigned int saver[], int len, int valid);


int main(){
	int i;
	int testcase;
	unsigned int ans;
	int length;
	unsigned int saver[200] = {'\0', };
	scanf("%d", &testcase);
	for(i=0; i<testcase; i++){
		scanf("%d", &length);
		ans = count_cases(saver, length, 0);
		printf("%u\n", ans);
	}
	return 0;
}

unsigned int count_cases(unsigned int saver[], int len, int valid){
	int ans;
	unsigned int case_num;
	if (saver[len+valid*100-1] != '\0'){
		return saver[len+valid*100-1];
	}
	if (len >= 5){
		case_num = count_cases(saver, len-2, (0 || valid))		// for boundary with (vertical, vertical)    
					+ count_cases(saver, len-4, (0 || valid))		// for boundary with (horizontal, horizontal)
					+ 2 * count_cases(saver, len-3, 1);						// for boundary with (vertical, horizontal)
				//	+ count_cases(len-3, 0);					// for boundary with (horizontal, vertical)
		if (case_num > 1000000007){
			case_num = case_num%1000000007;
		}
		//printf("for len %d, case_num: %u\n", len, case_num);
		saver[len+valid*100-1] = case_num;
		return case_num;
	}
	else if (len == 4){
		if ( valid == 0){
			return 2;
		}
		else {
			return 5;
		}
		
	}else if (len == 3){
		if ( valid == 0){
			return 2;
		}
		else {
			return 3;
		}
		
	}
	else if (len == 2){
		if ( valid == 0){
			return 0;
		}
		else {
			return 2;
		}
		
	}
	else if (len == 1){
		if ( valid == 0 ){
			return 0;
		} else {
			return 1;
		}
	}
	else{
		printf("wrong1\n");
	}

}

