#include<cstdio>
#define MAX_N 100
using namespace std;
int maze[MAX_N][MAX_N];
int nqueues(int n){
    return 0;
}
int sum = 0,inf = 1;  
void test(int row, int ld, int rd){
	if(row != inf){
		int pos = inf & ~(row | ld | rd);
		while(pos){
			int p = pos & -pos;
			pos -= p;
			test(row + p, (ld + p) << 1, (rd + p) >> 1);
		}
	}
	else
		sum++;
}
int main(){
	int n = 6;
	inf = (1 << n) - 1;
	test(0, 0, 0);
	printf("%d\n",sum);
	return 0;
}