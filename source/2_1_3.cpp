#include <iostream>

using namespace std;

template<class T>
int findNumber(T A[],int length,T v);

int main()
{
    float A[10];
    int length=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<length;++i)
        A[i]=rand()/10.0;
    float v=-1;
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