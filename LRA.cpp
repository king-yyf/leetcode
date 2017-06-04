#include<cstdio>
#include<stack>
#define MAX(a,b) (a) > (b) ? (a) : (b)
int a[100];
int maxSum(int n){
	stack<int> s;
	int maxSum = 0;
	for(int i = 0; i < n;){
		if(s.empty() || a[i] > a[s.top()])
			s.push(i++);
		else{
			int tmp = s.top();
			s.pop();
			int len = s.empty() ? i : i - s.top() - 1;
			maxSum = MAX(maxSum, a[tmp] * (len));
		}
	}
	return maxSum;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int ans = maxSum(n);
	return 0;
}