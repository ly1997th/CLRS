#include <iostream>
#include <cmath>
using namespace std;

template <class T>
T ordinary(T A[],T V,int length);

template <class T>
T Horner(T A[],T V,int length);

int main()
{
    int A[10];
    int length=sizeof(A)/sizeof(A[0]);
    for(int i=0;i<length;++i)
        A[i]=i;
    cout<<"coefficient(a1~an):";
    for(int i=0;i<length;++i)
        cout<<A[i]<<",";

    int V=2;
    int re=ordinary(A,V,length);
    cout<<endl<<"result:"<<re;
    re=Horner(A,V,length);
    cout<<endl<<"result:"<<re;

    return 0;
}

template <class T>
T ordinary(T A[],T V,int length)
{
    T sum=0;
    for(int i=0;i<length;++i)
        sum+=A[i]*pow(V,i);

    return sum;
}

template <class T>
T Horner(T A[],T V,int length)
{
    T sum=0;
    for(int i=0;i<length;++i)
    {
        sum=A[length-1-i]+sum*V;
    }
    return sum;
}