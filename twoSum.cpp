#include<vector>
#include<unordered_map>
using namespace std;
typedef pair<int, int> PAIR;
int arr[] = {2,3,6,8,10};

PAIR twoSum(int target){
	unordered_map<int, int> mapping;
	PAIR res;
	int len = sizeof(arr) / sizeof(arr[0]);
	for(int i(0); i != len; ++i){
		mapping[arr[i]] = i;
	}
	for(int i = 0; i != len; ++i){
		int gap = target - arr[i];
		if(mapping.find(gap) != mapping.end()){
			res.first = i + 1;
			res.second = mapping[gap] + 1;
			break;
		}
	}
	return res;
}
int main(){
	int tar = 9;
	PAIR ans = twoSum(9);
	printf("%d, %d\n",ans.first, ans.second);
	return 0;
}