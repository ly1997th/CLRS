#include <iostream>

using namespace std;

template <class T>
void merge_sort(T A[],int p,int r);

template <class T>
void merge(T A[],int p,int q,int r);

int main()
{
    //算法测试
    float A[10]={1,3,2};
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
    T M[q-p+2],N[r-q+1];
    for(int i=0;i<q-p+1;++i)
        M[i]=A[p+i];
    for(int i=0;i<r-q;++i)
        N[i]=A[q+i+1];
    M[q-p+1]=INT_MAX;N[r-q]=INT_MAX;  //哨兵，检查是否已经完成某个子序列的排序
    int i=0,j=0;
    for(int k=p;k<=r;++k)
    {
        if(M[i]<=N[j])
            {A[k]=M[i];++i;}
        else
            {A[k]=N[j];++j;}
    }

}