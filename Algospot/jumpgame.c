#include <stdio.h>

int board[100][100];
int dirty[100][100];
int edge_length;

void reset_dirty(int edge_length){
	int i,j;
	for(i=0; i<edge_length; i++){
		for(j=0; j<edge_length; j++){
			dirty[i][j] = 0;
		}
	}

}
int jump(int row, int col){
	int success = 0;
	int value;
	if ( dirty[row][col] == 1 )
		return success;
	dirty[row][col] = 1;

	value = board[row][col];
	if (row == edge_length-1 && col== edge_length-1 && value == 0){
		return 1;
	}
	if ( row+value < edge_length ){
		success = jump(row+value, col);
	}
	if ( (success == 0) && ( col+value < edge_length)){
		success = jump(row, col+value);
	}
	return success;

}

int main(){
	int testcase, a, i, j, k;
//	int edge_length;
	int ans;
	scanf("%d", &testcase);
	for(a=0; a<testcase; a++){
		scanf("%d", &edge_length);
		for(i=0; i<edge_length; i++){
			for(j=0; j<edge_length; j++){
				scanf("%d", &board[i][j]);
			}
		}
		reset_dirty(edge_length);
		ans = jump(0, 0);
		if (ans == 1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		
	}
	return 0;
}

