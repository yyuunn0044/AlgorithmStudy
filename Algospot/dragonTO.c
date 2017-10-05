#include <stdio.h>
#include <string.h>
char* xstring = "X+YF";
char* ystring = "FX-Y";
char* zstring = "FX";
char* nullstring = "";

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
	scanf("%d", &testcase);
	for(i=0; i<testcase; i++){
		scanf("%d %d %d", &gen, &start, &len);
		charstack[0] = 'Z';
		index[0] = 0;
		sp = 0;
		for(cursor = 1; cursor<start+len; ){
			thisChar = charstack[sp];
			thisStr = getstr(thisChar);
			thisLen = strlen(thisStr);

			if (index[sp] == thisLen){
				//POP STACK
				index[sp] = 0;
				charstack[sp] == '\0';
				sp--;
				if (sp ==0){
					break;
				}
				continue;
			}
			lastChar = thisStr[index[sp]];
			if ((sp < gen) && ((lastChar == 'X') || (lastChar == 'Y') || (lastChar == 'Z'))){
		
				index[sp] += 1;
				sp++;
				index[sp] = 0;
				charstack[sp] = lastChar;
				continue;
			}
			if (cursor >= start){
				printf("%c", lastChar);
			}
			cursor++;
			index[sp] += 1;
		}
		printf("\n");
	}
	
}
