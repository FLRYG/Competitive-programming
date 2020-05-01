#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll INF=1001001001001001001;

ll N;
ll A[200001];
ll sum[200001];

inline ll f(int i,int j){
    return sum[i]-sum[j]; 
}

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];

    repn(i,N) sum[i]=A[i]+sum[i-1];
    //repn(i,N) cout<<sum[i]<<' ';
    //cout<<endl;

    ll S,Q,R,T;
    ll diff1=INF, diff2=INF;
    for(int i=2;i<=N-2;i++){
        for(int j=1;j<i;j++){
            ll s=f(0,j);
            ll q=f(j,i);
            if(abs(s-q)<diff1){
                S=s;
                Q=q;
                diff1=abs(s-q);
            }
        }
        for(int j=i+1;j<N;j++){
            ll r=f(i,j);
            ll t=f(j,N);
            if(abs(r-t)<diff2){
                R=r;
                T=t;
                diff2=abs(r-t);
            }
        }
    }

    ll ans=max(max(S,Q),max(R,T))-min(min(S,Q),min(R,T));
    cout<<ans<<endl;
}