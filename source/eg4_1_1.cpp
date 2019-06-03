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

template<class T>
reStruct find_cross_max_subarray(T A[],int mid,int low,int high);
int main()
{
    int A[10];
    int length=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<length;++i)
        {A[i]=rand()%20-10;cout<<A[i]<<" ";}
    cout<<endl;
    reStruct re=find_max_subarray(A,0,length-1);
    cout<<re.sum<<" "<<re.low<<" "<<re.high;
    return 0;
}

template<class T>
reStruct find_max_subarray(T A[],int low,int high)
{
    if(low==high) return reStruct(A[low],low,high);
    int mid=(high-low)/2+low;
    reStruct re_left=find_max_subarray(A,low,mid);
    reStruct re_right=find_max_subarray(A,mid+1,high);
    reStruct re_mid=find_cross_max_subarray(A,mid,low,high);

    if(re_left.sum>re_right.sum&&re_left.sum>re_mid.sum) return re_left;
    if(re_right.sum>re_left.sum&&re_right.sum>re_mid.sum) return re_right;
    return re_mid;
}

template<class T>
reStruct find_cross_max_subarray(T A[],int mid,int low,int high)
{
    T left_max=A[mid],right_max=A[mid+1],sum=A[mid];
    int left_index=mid,right_index=mid+1;
    int i=mid-1;
    while(i>=low)
    {
        sum+=A[i];
        if(sum>left_max) 
        {
            left_max=sum;left_index=i;
        }
        --i;
    }
    i=mid+2;sum=A[mid+1];
    while(i<=high)
    {
        sum+=A[i];
        if(sum>right_max) 
        {
            right_max=sum;right_index=i;
        }
        ++i;
    }
    return reStruct(left_max+right_max,left_index,right_index);
}
