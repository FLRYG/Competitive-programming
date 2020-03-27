#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

template <class T>
inline void qswap(T& a,T& b);
template <class T>
void qsort(T* x,int left,int right);

int N,M;
int A[100001];
int B[100001];
pair<int,int> AB[100001];
int dp[100001];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>AB[i].first>>AB[i].second;

    sort(AB,AB+N);

    for(int i=1;i<=M;i++){
        
    }
}

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