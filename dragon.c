#include <stdio.h>

int main(){
	int testcase;
	int i, j, k;
	int gen, start, len;
	int cursor = 0;
	int sp=0, index=0;
	char index[51] = {0,};
	char alpha[51] = {'\0',};
	char xstring[] = "X+YF";
	char ystring[] = "FX-Y";
	char zstring[] = "FX";
	char thischar;
	// X -> X+YF
	// Y -> FX-Y
	// gen 0 FX 
	// gen 1 FX+YF
	// gen 2 FX+YF+FX-YF

	scanf("%d", &testcase);
	for(i=0; i<testcase; i++){
		scanf("%d %d %d", &gen, &start, &len);
		alpha[0] = 'Z';
		sp = 0;
		for(cursor=1; cursor<start; cursor++){
			thisChar = alpha[sp];
			thisStr = getstr(thisChar);
			thisLen = getlen(thisStr);

			if (index[sp] == thisLen){
				index[sp] == 0;
				alpha[sp] == '\0';
				sp--;
				if (sp==0){
					break;}		
				continue;
			}
			lastChar = thisStr(index[sp]);
			if (((lastChar=='X') || (lastChar=='Y') || (lastChar == 'Z')) && ( sp < gen)){
				// push
				index[sp]++;
				sp++;
				index[sp] = 0;
				alpha[sp] = lastChar;
				continue;
			}
			print(thisChar);
			index[sp]++;

		}
		
	
	}
	return 0;
}
