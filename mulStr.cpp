#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

typedef vector<int> bigint;

bigint make_bigint(string const & repr){
	bigint n;
	transform(repr.rbegin(), repr.rend(), back_inserter(n),\
		 [](char c){return c - '0';});
	return n;
}

string to_string(bigint const & n){
	string str;
	transform(find_if(n.rbegin(), prev(n.rend()), \
		[](char c){return c > '\0';}), n.rend(), back_inserter(str), \
			[](char c){return c + '0'});
	return str;
}

bigint operator * (bigint const & x, bigint const & y){
	bigint z(x.size() + y.size());
	for(size_t i = 0; i < x.size(); ++i){
		for(size_t j = 0; j < y.size(); ++j){
			z[i + j] += x[i] * y[i];
			z[i + j + 1] += z[i + j] / 10;
			z[i + j] %= 10;
		}
	}
	return z;
}
string mulStr(string s1, string s2){
	return to_string(make_bigint(s1) * make_bigint(s2));
}
int main(){
	string s1(""), s2("");
	return 0;
}