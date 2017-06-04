#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//f[i][j] A[0,i]和B[0,j]之间的最小编辑距离
int minDist(string & str1, string & str2){
	size_t n = str1.size();
	size_t m = str2.size();
	vector< vector<int> > f;
	f.resize(n + 1, vector<int>(m + 1));
	for(size_t i = 0; i <= n; ++i)
		f[i][0] = i;
	for(size_t i = 0; i <= n; ++i)
		f[0][i] = i;
	for(size_t i = 1; i <= n; ++i){
		for(size_t j = 1; j <= m; ++j){
			if(str1[i- 1] == str2[j - 1]){
				f[i][j] = f[i - 1][j - 1];
			}else{
				int mn = min(f[i - 1][j], f[i][j - 1]);
				f[i][j] = 1 + min(f[i - 1][j - 1], mn);
			}
		}
	}
	return f[n][m];
}

int minDist2(string & str1, string & str2){
	if(str1.length() < str2.length())
		return minDist2(str2, str1);
	vector<int> f(str2.length() + 1);
	int upper_left = 0;
	for(size_t i = 0; i <= str2.size(); ++i){
		f[0] = i;
	}
	for(size_t i = 0; i <= str1.size(); ++i){
		upper_left = f[0];
		f[0] = i;
		for(size_t j = 1; j <= str2.size(); ++j){
			int upper = f[j];
			if(str1[i - 1] == str2[j - 1])
				f[j] = upper_left;
			else
				f[j] = 1 + min(upper_left, min(f[j], f[j - 1]));
			upper_left = upper;
		}
	}
	return f[str2.length()];
}
int main(){
	string str1("hello"), str2("world");
	int ans = minDist(str1, str2);
	printf("%d\n",ans);
	ans = minDist2(str1, str2);
	printf("%d\n",ans);
	return 0;
}