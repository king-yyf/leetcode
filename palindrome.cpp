#include<string>
#include<iterator>
#include<cctype>
#include<iostream>
#include<algorithm>
using namespace std;

bool isPalindrome(string s){
	transform(s.begin(),s.end(),s.begin(),::tolower);
	auto left = s.begin(), right = prev(s.end());
	while(left < right){
		if(!isalnum(*left)) ++left;
		else if(!isalnum(*right)) --right;
		else if(*left != *right) return false;
		else {
			++left;
			--right;
		}
	}
	return true;
}
int main(){
	string s1("A man, a plan a canal: Panama");
	string s2("rece a car");
	bool ok1 = isPalindrome(s1);
	bool ok2 = isPalindrome(s2);
	if(ok1) cout<<"s1: "<<s1<<endl;
	if(ok2) cout<<"s2: "<<s2<<endl;
	return 0;
}