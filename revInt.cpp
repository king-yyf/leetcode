#include<cstdio>
using namespace std;
bool isPalindrome(int x){
	if(x < 0) return false;
	int d =1;
	while(x / d >= 10) d *= 10;
	
	while(x > 0){
		int q = x / d;
		int r = x % d;
		if(q != r) return false;
		x = x % d / 10;
		d /= 100;
	}
	return true;
}
int reverse(int x){
	int r =0;
	while(x){
		r = r * 10 + x % 10;
		x /= 10;
	}
	return r;
}
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		int ans = reverse(n);
		printf("%d\n", ans);
	}
	return 0;
}