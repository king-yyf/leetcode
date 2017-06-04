#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;

void merger(int * arr, int n, bool asd){
	for(int step = (n >> 1); step > 0; step >>= 1){
		for(int i = 0; i < n; i += (step << 1)){
			for(int j = i, k = 0; k < step; ++j, ++k){
				if(asd){            //升序
					if(arr[j] > arr[j + step])
						swap(arr[j], arr[j + step]);
				}else{
					if(arr[j] < arr[j + step])
						swap(arr[j], arr[j + step]);
				}		
			}
		}
	}
}

void bitonic_sort(int * arr, int n){
	for(int step = 2; step <= n; step <<= 1){
		for(int i = 0; i < n; i += (step << 1)){
			merger((arr + i), step, true);
			if(i + step < n)
				merger((arr + i + step), step, false);
		}
	}
}

//输出数组，测试用
void printArray(int * arr, int n){
	printf("[%d",arr[0]);
	for(int i = 1; i < n; ++i){
		printf(",%d", arr[i]);
	}
	printf("]\n");
}

void segmentedBitonicSort(float* data, int* seg_id, int* seg_start, int n, int m){
	
}
int main(){
	int arr[16] = {10,20,5,9,3,8,12,14,90,0,60,40,23,35,95,18};
	bitonic_sort(arr, 16);
	printArray(arr, 16);
	return 0;
}