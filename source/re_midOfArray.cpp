#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

template <class T>
T bubbleSort(T A[],int length)
{
    T key;
    for(int i=0;i<=length/2;++i)
        for(int j=length-1;j>i;--j)
        {
            if(A[j]<A[j-1]) 
            {
                key=A[j-1];A[j-1]=A[j];A[j]=key;
            }
        }
    return A[length/2];
}

template<class T>
T insertionSort(T A[],int length)
{
    for(int j=1;j<length;++j)
    {
        T key=A[j];
        int i=j-1;
        while(i>=0&&A[i]<key)
        {
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
    return A[length/2];
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
template <class T>
T mergeSort(T A[],int length)
{
    T temp;
    if(length==9)
    {
        for(int i=0;i<3;++i)
        {
            int index=i*3;
            if(A[index]>A[index+1]) {temp=A[index];A[index]=A[index+1];A[index+1]=temp;}
            if(A[index+2]<A[index+1]) 
            {
                temp=A[index+1];A[index+1]=A[index+2];A[index+2]=temp;
                if(A[index+1]<A[index])
                {temp=A[index];A[index]=A[index+1];A[index+1]=temp;}
            }
        }
        //merge(A,0,2,5);
        int p=0,q=2,r=5;
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
        p=0;q=5;r=8;i=0;j=0;
        T W[q-p+1],Q[r-q];    
        for(int i=0;i<q-p+1;++i)
            Q[i]=A[p+i];
        for(int i=0;i<r-q;++i)
            Q[i]=A[q+i+1];
        for(int k=p;k<=r;++k)
        {
            if((W[i]<=Q[j]&&i<q-p+1)||j==r-q)   //检查某个序列是否已经完成合并排序
                {A[k]=W[i];++i;}
            else
                {A[k]=Q[j];++j;}
        }
        return A[4];
    }
    if(length==5)
    {
        T key;
        for(int i=0;i<=length/2;++i)
            for(int j=length-1;j>i;--j)
            {
                if(A[j]<A[j-1]) 
                {
                    key=A[j-1];A[j-1]=A[j];A[j]=key;
                }
            }
        return A[length/2];
    }
    return 0;
}


int main()
{
    const int mod1=5,mod2=9;
    int A[450000],t1[mod1],t2[mod2];
    int length=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<length;++i)
        A[i]=rand()%1000;

    //冒泡排序，注意只用排序一半就可以找出中位数，比全部排序快30%左右的效率
    chrono::steady_clock::time_point time1=chrono::steady_clock::now();
    for(int i=0;i<length/mod1;++i)
    {
        for(int j=i*mod1;j<(i+1)*mod1;++j)
            t1[j-i*mod1]=A[j];
        //cout<<bubbleSort(t1,mod1)<<" ";
        bubbleSort(t1,mod1);
    }
    chrono::steady_clock::time_point time2 = chrono::steady_clock::now();
    chrono::duration<double> time_used=chrono::duration_cast<chrono::duration<double>>(time2-time1);
    double time_cost1=time_used.count()*1000;
    time1=chrono::steady_clock::now();
    for(int i=0;i<length/mod2;++i)
    {
        for(int j=i*mod2;j<(i+1)*mod2;++j)
            t2[j-i*mod2]=A[j];
        //cout<<bubbleSort(t2,mod2)<<" ";
        bubbleSort(t2,mod2);
    }
    time2 = chrono::steady_clock::now();
    time_used=chrono::duration_cast<chrono::duration<double>>(time2-time1);
    double time_cost2=time_used.count()*1000;
    cout<<endl<<"bubble sort:"<<"  5 nums:"<<time_cost1<<"(ms)"<<"  9 nums:"<<time_cost2<<"(ms)"<<endl;


    //插入排序，时间消耗与冒泡排序相比，在数据较多时有优势
    time1=chrono::steady_clock::now();
    for(int i=0;i<length/mod1;++i)
    {
        for(int j=i*mod1;j<(i+1)*mod1;++j)
            t1[j-i*mod1]=A[j];
        //cout<<insertionSort(t1,mod1)<<" ";
        insertionSort(t1,mod1);
    }
    time2=chrono::steady_clock::now();
    time_used=chrono::duration_cast<chrono::duration<double>>(time2-time1);
    time_cost1=time_used.count()*1000;
    time1=chrono::steady_clock::now();
    for(int i=0;i<length/mod2;++i)
    {
        for(int j=i*mod2;j<(i+1)*mod2;++j)
            t2[j-i*mod2]=A[j];
        //cout<<insertionSort(t2,mod2)<<" ";
        insertionSort(t2,mod2);
    }
    time2 = chrono::steady_clock::now();
    time_used=chrono::duration_cast<chrono::duration<double>>(time2-time1);
    time_cost2=time_used.count()*1000;
    cout<<endl<<"insert sort:"<<"  5 nums:"<<time_cost1<<"(ms)"<<"  9 nums:"<<time_cost2<<"(ms)"<<endl;

    time1=chrono::steady_clock::now();
    for(int i=0;i<length/mod1;++i)
    {
        for(int j=i*mod1;j<(i+1)*mod1;++j)
            t1[j-i*mod1]=A[j];
       //cout<<insertionSort(t1,mod1)<<" ";
        mergeSort(t1,mod1);
    }
    time2=chrono::steady_clock::now();
    time_used=chrono::duration_cast<chrono::duration<double>>(time2-time1);
    time_cost1=time_used.count()*1000;
    time1=chrono::steady_clock::now();
    for(int i=0;i<length/mod2;++i)
    {
        for(int j=i*mod2;j<(i+1)*mod2;++j)
            t2[j-i*mod2]=A[j];
        //cout<<insertionSort(t2,mod2)<<" ";
        mergeSort(t2,mod2);
    }
    time2 = chrono::steady_clock::now();
    time_used=chrono::duration_cast<chrono::duration<double>>(time2-time1);
    time_cost2=time_used.count()*1000;
    cout<<endl<<"merge sort:"<<"  5 nums:"<<time_cost1<<"(ms)"<<"  9 nums:"<<time_cost2<<"(ms)"<<endl;

    return 0;
}
