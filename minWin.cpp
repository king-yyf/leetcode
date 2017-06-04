#include<iostream>
#include<string>
#include<vector>
using namespace std;
string minWin(string s, string t){
	if(s.empty() || s.size() < t.size()) return "";
	vector<int> appear(256, 0), expect(256, 0);
	for(size_t i = 0; i < t.size(); ++i)
		expect[t[i]] ++;
	int minWidth = 0x3f3f3f3f, min_start = 0;
	int wnd = 0, app = 0;
	for(size_t wnd_end = 0; wnd_end < s.size(); wnd_end++){
		if(expect[s[wnd_end]] > 0){
			appear[s[wnd_end]]++;
			if(appear[s[wnd_end]] <= expect[s[wnd_end]])
				app++;
		}
		if(app == t.size()){
			while(appear[s[wnd]] > expect[s[wnd]] || expect[s[wnd]] == 0){
				appear[s[wnd]]--;
				wnd++;
			}
			if(minWidth > (wnd_end - wnd + 1)){
				minWidth = wnd_end - wnd + 1;
				min_start = wnd;
			}
		}
	}
	if(minWidth == 0x3f3f3f3f) return "";
	else return s.substr(min_start, minWidth);
 }
int main(){
	string str1("adobecodebanc"), str2("abc");
	string ans = minWin(str1, str2);
	cout<<ans<<endl;
}