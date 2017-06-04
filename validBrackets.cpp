#include<cstdio>
#include<cstring>
#include<stack>
#include<map>
using namespace std;
char str[100];
map<char,char> valid;
bool isValid(){
	stack<char> s;
	const int len = strlen(str);
	for(int i = 0; i != len; ++i){
		if(str[i] == '{' || str[i] == '(' || str[i] == '['){
			s.push(str[i]);
		}
		else{
			char c = s.top();
			if(c == valid[str[i]])
				s.pop();
			else
				return false;
		}
	}
	return s.empty();
}

int main(){
	valid['}'] = '{';
	valid[']'] = '[';
	valid[')'] = '(';
	while(scanf("%s",str) != EOF){
		bool ok = isValid();
		if(ok) printf("%s is valid\n",str);
		else printf("%s is not valid\n",str);
	}
	return 0;
}