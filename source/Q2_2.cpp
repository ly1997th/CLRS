#include <iostream>

using namespace std;

template <class T>
void bubbleSort(T A[],int length);

int main()
{
    float A[10];
    for(int i=0;i<10;++i)
        A[i]=rand()/10.0;
    int length=sizeof(A)/sizeof(A[0]);
    bubbleSort(A,length);
    for(int i=0;i<10;++i)
        cout<<A[i]<<" ";
    return 0;
}

template <class T>
void bubbleSort(T A[],int length)
{
    T key;
    for(int i=0;i<length-1;++i)
        for(int j=length-1;j>i;--j)
        {
            if(A[j]<A[j-1]) 
            {
                key=A[j-1];A[j-1]=A[j];A[j]=key;
            }
        }
}