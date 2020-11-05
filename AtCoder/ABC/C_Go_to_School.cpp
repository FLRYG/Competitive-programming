#include <iostream>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int N;
int ans[100000];
int A[100000];

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

    qswap(ans[(right+left)/2],ans[right-1]);
    qswap(x[(right+left)/2],x[right-1]);
    int i=left;
    for(int j=left;j<right-1;j++){
        if(x[j]<pivod){
            qswap(ans[i],ans[j]);
            qswap(x[i++],x[j]);
        }
    }
    qswap(ans[i],ans[right-1]);
    qswap(x[i],x[right-1]);

    qsort(x,left,i);
    qsort(x,i+1,right);
}

int main(){
    cin>>N;
    rep(i,N){
        cin>>A[i];
        ans[i]=i+1;
    }

    qsort(A,0,N);

    rep(i,N) cout<<ans[i]<<' ';
}