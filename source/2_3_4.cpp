#include <iostream>

using namespace std;

template<class T>
void insertion_sort(T A[],int length);

template<class T>
void insertion(T A[],int p,int length);

int main()
{
    float A[9];
    int length=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<length;++i)
        A[i]=rand()/10.0;
    insertion_sort(A,length);
    for(int i=0;i<length;++i)
        cout<<A[i]<<" ";
    return 0;
}

//排序，使用降序排列
template<class T>
void insertion_sort(T A[],int length)
{
    int p=length-1;
    insertion(A,p,length);
}
template<class T>
void insertion(T A[],int p,int length)
{
    if(p>0) insertion(A,p-1,length);
    int j=p;int i=j-1;
    T key=A[j];
    while(i>=0&&A[i]<key)
    {
        A[i+1]=A[i];
        i=i-1;
    }
    A[i+1]=key;
}