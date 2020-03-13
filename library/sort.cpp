#include <iostream>
using namespace std;

template <class T>
inline void qswap(T& a,T& b);
template <class T>
void qsort(T* x,int left,int right);

template <class T>
inline void qswap(T& a,T& b){
    T tmp=a;
    a=b;
    b=tmp;
}

template <class T>
void qsort(T* x,int left,int right){
    if(right-left<=1) return;
    int pivod=x[(right+left)/2];

    qswap(x[(right+left)/2],x[right-1]);
    int i=left;
    for(int j=left;j<right-1;j++){
        if(x[j]<pivod){
            qswap(x[i++],x[j]);
        }
    }
    qswap(x[i],x[right-1]);

    qsort(x,left,i);
    qsort(x,i+1,right);
}

int main(){
    int a[]={5,2,7,0,3,6,8,4,1,2,9};
    qsort(a,0,sizeof(a)/sizeof(a[0]));
    for(auto x:a){
        cout<<x<<' ';
    }
    cout<<'\n';

    double b[]={2.4,3.7,7.9,0.4,7.1,9.6,4.3};
    qsort(b,0,sizeof(b)/sizeof(b[0]));
    for(auto x:b){
        cout<<x<<' ';
    }
}