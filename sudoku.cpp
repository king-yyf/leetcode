#include<cstdio>
#include<cctype>
using namespace std;
int maze[10][10];
void sudokuSolver(){
	
}
int main(){
	char str[10];
	for(int i = 0; i < 9; ++i){
		scanf("%s",str);
		for(int j = 0; j < 9; ++j){
			if(isdigit(str[i]))
				maze[i][j] = str[i] - '0';
		}
	}
	sudokuSolver();
	for(int i = 0; i < )
	return 0;
}