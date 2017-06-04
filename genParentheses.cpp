#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> genPar(int n){
	if(n == 0) return vector<string>(1,"");
	if(n == 1) return vector<string>(1,"()");
	vector<string> result;
	for(int i = 0; i < n; ++i){
		for(auto inner : genPar(i)){
			for(auto outer : genPar(n - 1 - i))
				result.push_back("(" + inner + ")" + outer);
		}
	}
	return result;
}

int main(){
	int n;
	while(cin >> n){
		vector<string> v = genPar(n);
		for(size_t i = 0; i < v.size(); ++i){
			cout<<v[i]<<endl;
		}
	}
	return 0;
}
