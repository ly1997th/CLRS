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

int main()
{
    int mod1=5;int mod2=9;
    int A[450000],t1[5],t2[9];
    int length=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<length;++i)
        A[i]=rand();

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

    return 0;
}
