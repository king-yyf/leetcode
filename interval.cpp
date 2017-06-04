#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> start;
vector<int> ends;
void insertInterval(int s, int e){
	int pos1 = lower_bound(ends.begin(), ends.end(), s) - ends.begin();
	int pos2 = lower_bound(ends.begin(), ends.end(), e) - ends.begin();
	if(pos2 < ends.size() && start[pos2] > e){
		pos2--;
	}
	ends[pos1]= ends[pos2];
	for(int i  = pos2 ; i > pos1; --i){
		start.erase(start.begin() + i);
		ends.erase(ends.begin() + i);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int s, e;
	for(int i = 0; i < n; ++i){		
		scanf("%d%d",&s, &e);
		start.push_back(s);
		ends.push_back(e);
	}
	scanf("%d%d",&s,&e);
	insertInterval(s,e);
	for(size_t i = 0; i < start.size(); ++i){
		printf("[%d, %d], ",start[i], ends[i]);
	}
	printf("\n");
	return 0;
}