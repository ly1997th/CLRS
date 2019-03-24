#include <iostream>

using namespace std;

template<class T>
void insertion_sort(T A[10]);

int main()
{
    float A[10];
    for(int i=0;i<10;++i)
        A[i]=rand()/10.0;
    insertion_sort(A);
    for(int i=0;i<10;++i)
        cout<<A[i]<<" ";
    return 0;
}

//排序，使用降序排列
template<class T>
void insertion_sort(T A[10])
{
    for(int j=1;j<10;++j)
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
}