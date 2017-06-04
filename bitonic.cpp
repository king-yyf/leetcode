#include <stdio.h>    
#include <iostream>    
#include <vector>  
using namespace std;    
  
void segmentedBitonicSort(float* data, int* seg_id, int* seg_start, int n, int m)  
{  
    ////判断输入是否有误  
    if(n <= 0 || m <= 0||m>n)    
    {    
        cout<<"Input error!n>m>0"<<endl;  
        return;    
    }    
    if(!(seg_start[m]==n && seg_id[n-1]==(m-1)))    
    {    
        cout<<"Input error! seg_start[m]==n,seg_id[n-1]==(m-1)"<<endl;  
        return;    
    }   
    //先段内排序  
    for(int d=0;d<m;d++)  
    {  
        int len=1;  
        while (len < seg_start[d+1]-seg_start[d])//循环退出的条件   
            len = len << 1;//寻找大于n的最小的2的幂次方len  
  
        float Max=999999;//作为填充数  
        vector<float> segdata(len);  
        // vector<float> segdata(len);  
        for (int i = 0; i < seg_start[d+1]-seg_start[d]; i++)   
        {  
            segdata[i]=data[seg_start[d]+i];  
        }  
        //如果len > n,就说明数组的个数不够，要将个数填充到len个   
        for (int i = seg_start[d+1]-seg_start[d]; i < len; i++)    
            segdata[i] =Max;    
        ///////对整个数组进行排序  
        for (int step = 2; step <= len; step <<= 1)   
        {    
            //////内部循环可任意交换  
            for (int i = 0; i < len; i += step<<1)//1  
            {    
                ///升序排  
                for (int step0 = step>>1 ;step0 >0 ;step0 >>= 1)// 2  
                {    
                    for (int j = 0; j < step; j += step0<<1)//3  
                    {    
                        for (int k = 0; k < step0; ++k)//4  
                        {  
                            if (segdata[i+j+k] > segdata[i+j+k+step0]||segdata[i+j+k]!=segdata[i+j+k])  //交换数据使升序排列,同时判断二者之中是否有NaN  
                            {  
                                //交换data   
                                float T=segdata[i+j+k];  
                                segdata[i+j+k]=segdata[i+j+k+step0];  
                                segdata[i+j+k+step0]=T;  
                            }  
                        }   
                    }  
                }  
  
                if (i + step < len)   
                {  //////内部循环可任意交换  
                    for (int step0= step>>1;step0 >0 ;step0 >>= 1) //1  
                    {    
                        for (int j = 0; j < step; j += step0<<1) //2  
                        {    
                            for (int k = 0; k < step0; ++k) //3  
                            {    
                                if (segdata[i + step+j + k] < segdata[i + step+j + step0 +k]  
                                ||segdata[i + step+j + step0 +k]!=segdata[i + step+j + step0 +k]) //交换数据使降序排列,同时判断二者之中是否有NaN  
                                {  
                                    //交换data   
                                    float T=segdata[i+step+j+k];  
                                    segdata[i+step+j+k]=segdata[i+step+j+k+step0];  
                                    segdata[i+step+j+k+step0]=T;  
                                }  
                            }    
                        }    
                    }    
                }     
            }  
        }  
        for (int i = seg_start[d]; i < seg_start[d+1]; i++)   
        {  
            data[i]=segdata[i-seg_start[d]];  
            if(data[i]==Max)  
                data[i]=sqrt(-1.f);  
        }  
    }  
}  
void main()  
{  
    float data[11]={ 0,sqrt(-1.f) -100 , 2, 100, 4, 0.5,sqrt(-1.f), sqrt(-1.f), 3, 0.1, 2};  
    int seg_id[11]={0, 0, 0, 1, 1, 2, 2, 2, 2,3,3};  
    int seg_start[5]={0,3,5,9,11};  
    int n=11;  
    int m=4;  
  
    //调用分段双调函数  
    segmentedBitonicSort(data,seg_id,seg_start,n,m);  
    //输出  
  
    for (int i = 0; i < n;++i) {    
        cout << data[i] <<"\t";    
    }    
    cout << endl;   
}  
