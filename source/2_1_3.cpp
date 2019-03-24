#include <iostream>

using namespace std;

template<class T>
int findNumber(T A[],int length,T v);

int main()
{
    float A[10];
    for(int i=0;i<10;++i)
        A[i]=rand()/10.0;
    int length=sizeof(A)/sizeof(A[0]);
    float v=A[8];
    findNumber(A,length,v)<0?cout<<"NIL":cout<<findNumber(A,length,v);  
    return 0;
}

//查找元素
template<class T>
int findNumber(T A[],int length,T v)
{
    for(int j=0;j<length;++j)
    {
        if(v==A[j]) return j;
    }
    return -1;
}