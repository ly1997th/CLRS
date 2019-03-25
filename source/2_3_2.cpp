#include <iostream>

using namespace std;

template <class T>
void merge_sort(T A[],int p,int r);

template <class T>
void merge(T A[],int p,int q,int r);

int main()
{
    //算法测试
    float A[30];
    int length=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<length;++i)
        A[i]=rand()/10.0;
    merge_sort(A,0,length-1);

    for(int i=0;i<length;++i)
        cout<<A[i]<<" ";
    return 0;
}

//归并排序,递归排序
template <class T>
void merge_sort(T A[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

//归并已经排序完成的子序列
template <class T>
void merge(T A[],int p,int q,int r)
{
    T M[q-p+1],N[r-q];    
    for(int i=0;i<q-p+1;++i)
        M[i]=A[p+i];
    for(int i=0;i<r-q;++i)
        N[i]=A[q+i+1];
    int i=0,j=0;
    for(int k=p;k<=r;++k)
    {
        if((M[i]<=N[j]&&i<q-p+1)||j==r-q)   //检查某个序列是否已经完成合并排序
            {A[k]=M[i];++i;}
        else
            {A[k]=N[j];++j;}
    }
}