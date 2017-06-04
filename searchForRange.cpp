#include<cstdio>
#include<algorithm>
#include<iterator>
using namespace std;
typedef pair<int, int> PAIR;

PAIR serverRange(int a[], int n, int target){
	int l = lower_bound(a, a + n, target) - a;
	int u = upper_bound(a, a + n, target) - a;
	if(l >= n) return PAIR(-1,-1);
	else return PAIR(l,u - 1);
}
int main(){
	int arr[] = {5,7,7,8,8,10};
	PAIR p = serverRange(arr, 6, 10 );
	printf("Range:[%d, %d]\n",p.first, p.second);
	return 0;
}