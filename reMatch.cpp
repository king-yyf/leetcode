//实现正则表达式匹配，支持 . //*，'.'匹配任意一个字符，'*'匹配0个或多个字符

#include<cstdio>
#include<cstring>

bool isMatch(const char *s, const char * p){
	if(*p == '\0') return *s == '\0';
	if(*(p + 1) != '*'){
		if(*p == *s || (*p == '.' && *s != '\0'))
			return isMatch(s + 1, p + 1);
		else
			return false;
	}else{
		while(*p == *s || (*p == '.' && *s != '\0')){
			if(isMatch(s, p + 2))
				return true;
			s++;
		}
		return isMatch(s, p + 2);
	}
}
int main(){
	return 0;
}