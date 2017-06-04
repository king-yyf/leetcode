#include<cstdio>
#include<vector>
#include<cstdlib>
#include<ctime>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define INF 0x3f3f3f3f
using namespace std;
int maze[][5] = {
	{47,34,23,50,5},
	{38,26,33,25,47},
	{16,10,14,40,39},
	{19,49,28,3,2}
};
int minPathSum(int m, int n){
	vector<int> f(n, INF);
	f[0] = 0;
	for(int i = 0; i < m; ++i){
		printf("Line: %d\n", i);
		f[0] += maze[i][0];
		printf("f[0]: %d\t",f[0]);
		for(int j = 1; j < n; ++j){
			f[j] = MIN(f[j], f[j - 1]) + maze[i][j];
			printf("f[%d]: %dt",j, f[j]);
 		}
		printf("\n");
	}
	return f[n - 1];
}
int main(){
	srand(time(0));
	int m = 4,n = 5;
	// for(int i = 0; i < m; ++i){
// 		for(int j = 0; j < n; ++j){
// 			maze[i][j] = rand()%50 + 1;
// 		}
//	}
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j){
			printf("%d\t",maze[i][j]);
		}
		printf("\n");
	}
	int ans = minPathSum(m,n);
	printf("minPathSum: %d\n",ans);
	return 0;
}