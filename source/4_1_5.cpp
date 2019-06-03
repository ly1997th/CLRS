#include <iostream>
#include <vector>
using namespace std;

struct result
{
    double sum;
    int low;
    int high;
    result(double sum,int low,int high):sum(sum),low(low),high(high){};
};
typedef struct result reStruct;

template<class T>
reStruct find_max_subarray(T A[],int low,int high);

int main()
{
    int A[10];
    int length=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<length;++i)
        {A[i]=rand()%8-5;cout<<A[i]<<" ";}
    cout<<endl;
    reStruct re=find_max_subarray(A,0,length-1);
    cout<<re.sum<<" "<<re.low<<" "<<re.high;
    return 0;
}

template<class T>
reStruct find_max_subarray(T A[],int low,int high)
{
    if(low==high) return reStruct(A[low],low,high);
    T a_sum=A[low],b_sum;
    T sum_array[high-low+1];
    int a_left=low,a_right=low;
    int b_left,b_right;
    int i=low+1;
    sum_array[0]=A[low];
    while(i<=high)
    {
        int j=i;
        sum_array[j-low]=A[j];
        b_sum=sum_array[j-low];
        b_left=j;
        --j;
        while(j>=low)
        {
            sum_array[j]+=A[i];
            if( sum_array[j]>b_sum) {b_sum=sum_array[j];b_left=j;}
            --j;
        }
        b_right=i;
        if(a_sum<b_sum) { a_sum=b_sum;a_left=b_left;a_right=b_right;}
        ++i;
    }
    return reStruct(a_sum,a_left,a_right);
}

