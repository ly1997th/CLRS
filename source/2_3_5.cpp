#include <iostream>

using namespace std;

template <class T>
void merge_sort(T A[],int p,int r);

template <class T>
void merge(T A[],int p,int q,int r);

template <class T>
void merge_use(T A[],int length);

template<class T>
int findNumber(T A[],int length,T v);

int main()
{
    float A[10]={10};
    int length=sizeof(A)/sizeof(A[0]);
    // for(int i=0;i<length;++i)
    //     A[i]=rand()/10.0;
    merge_use(A,length);
    float v=10;
    findNumber(A,length,v)<0?cout<<"NIL":cout<<findNumber(A,length,v);  
    return 0;
}

//查找元素
template<class T>
int findNumber(T A[],int length,T v)
{
    int end=length-1;
    int start=0;
    while((start+end)/2>=0)
    {
        if(A[(start+end)/2]==v) return (start+end)/2;
        if(A[(start+end)/2]<v)  start=(start+end)/2+1;
        if(A[(start+end)/2]>v)  end=(start+end)/2-1;
        if(start==end&&A[start]!=v) return -1;
    }
}

//封装
template <class T>
void merge_use(T A[],int length)
{
    merge_sort(A,0,length-1);
}

//归并排序,递归排序,按非降序
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