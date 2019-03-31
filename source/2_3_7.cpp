#include <iostream>

using namespace std;

template <class T>
void merge_sort(T A[],int p,int r);

template <class T>
void merge(T A[],int p,int q,int r);

template <class T>
int TwoSum(T A[],T V,T re[],int length);

int main()
{
    //算法测试
    int A[4]={1,3,2,4};
    int length=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<length;++i)
        cout<<A[i]<<" ";
    cout<<endl;
    merge_sort(A,0,length-1);
    int V=5;int re[length*2];
    int num=TwoSum(A,V,re,length);
    cout<<V<<":";
    for(int i=1;i<=num;++i)
    {
        cout<<"<"<<re[(i-1)*2]<<","<<re[i*2-1]<<">"<<" ";
    }
    return 0;
}


template <class T>
int TwoSum(T A[],T V,T re[],int length)
{
    if(A[0]>V) return 0;
    int p=0;
    for(int i=0;i<length-1;++i)
    {
        if(A[i]>V) break;
        else
        {
            int j=i+1;
            while(A[j]<=V&&j<length)
            {
                if(A[i]+A[j]==V) 
                {re[p]=A[i];re[++p]=A[j];++p;}
                ++j;
            }
        }        
    }
    return p/2;
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