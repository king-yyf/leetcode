#include<cstdio>
#include<cstring>
#define N 100

int next[N];
char str1[N];
char str2[N];
void getNext(const char * pattern){
	const int m = strlen(pattern);
	next[0] = -1;
	for(int i = 1, j = -1; i < m; ++i){
		while(j > -1 && pattern[j + 1] != pattern[i])
			j = next[j];
		if(pattern[i] == pattern[j + 1]) j++;
		next[i] = j;
	}
}
int kmp(const char * text, const char * pattern){
	const int n = strlen(text), m = strlen(pattern);
	if(n == 0 || m == 0) return 0;
	for(int i = 0, j = -1; i < n; ++i){
		while(j > -1 && pattern[j + 1] != text[i])
			j = next[j];
		if(text[i] == pattern[j + 1]) j++;
		if(j == n - 1){
			return i - j;
		}
	}
	return -1;
}
int main(){
	scanf("%s%s",str1,str2);
	printf("%s\n",str1);
	printf("%s\n",str2);
	getNext(str2);
	int ans = kmp(str1,str2);
	printf("%d\n",ans);
	return 0;
}