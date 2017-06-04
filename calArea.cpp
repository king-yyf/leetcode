#include<vector>
#include<iostream>
#include<stack>
#define max(a,b) (a) > (b) ? (a) : (b)
#define min(a,b) (a) < (b) ? (a) : (b)
using namespace std;

typedef pair<int, int> PAIR;
int trap(int A[],int n){
	vector<int> max_left(n,0);
	vector<int> max_right(n,0);
	
	for(int i = 1; i < n; ++i){
		max_left[i] = max(max_left[i - 1], A[i - 1]);
		max_right[n - 1 - i] = max(max_right[n - i], A[n - i]);
	}
	int sum = 0;
	for(int i = 0; i < n; ++i){
		int height = min(max_left[i], max_right[i]);
		if(height > A[i]) sum += height - A[i];
	}
	return sum;
}
int trapPlus(int A[], int n){
	int max = 0;
	for(int i = 0; i < n; ++i)
		if(A[i] > A[max]) max =i;
	int water = 0;
	for(int i = 0, peak = 0; i < max; i++){
		if(A[i] > peak) 
			peak = A[i];
		else
			water += peak - A[i];
	}
	for(int i = n - 1, top = 0; i > max; --i){
		if(A[i] > top)
			top = A[i];
		else
			water += top - A[i];
	}
	return water;
}
int trap2(int a[], int n){
	stack<PAIR> s;
	int water = 0;
	for(int i = 0; i < n; ++i){
		int height = 0;
		while(!s.empty()){
			int bar = s.top().first;
			int pos = s.top().second;
			water += (min(bar,a[i]) - height) * (i - pos - 1);
			height = bar;
			if(a[i] < bar) break;
			else
				s.pop();
		}
		s.push(PAIR(a[i], i));
	}
	return water;
}
int main(){
	int a[] = {0,1,3,2,1,2,1,0,1,2,1};
	cout<<trap(a,11)<<endl;
	cout<<trapPlus(a,11)<<endl;
	cout<<trap2(a,11)<<endl;
	return 0;
}