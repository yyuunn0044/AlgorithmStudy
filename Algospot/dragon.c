#include <stdio.h>
#include <string.h>
char* xstring = "X+YF";
char* ystring = "FX-Y";
char* zstring = "FX";
char* nullstring = "";
int skip[51];

char* getstr(char thisChar){
	if (thisChar == 'X'){
		return xstring;
	}
	else if (thisChar == 'Y'){
		return ystring;
	}
	else if (thisChar == 'Z'){
		return zstring;
	}
	else{
		return nullstring;
	}
}
void calcSkip(){
	int i=0;
	int MAX= 1000000000+1;
	skip[0] = 1;
	for(i=1; i<52; i++){
		if ((2 + (2 * skip[i-1]))>MAX){
			skip[i] = MAX;
		} else{
			skip[i] = 2 + (2 * skip[i-1]);
		}
	}
}
char getOneChar(char seed, int gen, int cursor){
//	printf("for seed %c, gen %d, cursor %d\n", seed, gen, cursor);
	int i=0;
	char* thisStr = getstr(seed);
	if (gen == 0){
		return thisStr[cursor];
	}

	for(i=0; i<strlen(thisStr); i++){
		if ( thisStr[i] == 'X' || thisStr[i]=='Y'){
			if ( cursor >= skip[gen] ){
				cursor -= skip[gen];
//				printf("skip %d\n", skip[gen]);
			}
			else {
				return getOneChar(thisStr[i], gen-1, cursor);
			}
		}
		else if (cursor>0){
			cursor -= 1;
		}
		else{
			return thisStr[i];
		}
	}	
}
int main(){
	int testcase;
	int i,j,k;
	int gen, start, len;
	int index[51];
	int charstack[51];
	int sp, cursor;
	char thisChar;
	char* thisStr, lastChar;
	int thisLen;
	calcSkip();
	scanf("%d", &testcase);
	for(i=0; i<testcase; i++){
		scanf("%d %d %d", &gen, &start, &len);
		start -= 1;
		for(cursor=start; cursor<start+len; cursor++){
			if (cursor == 0){
				thisChar = 'F';
			} else {
				thisChar = getOneChar('X', gen, cursor-1);
			}
			printf("%c", thisChar);
		}
		printf("\n");
		
		
	}
	
}
