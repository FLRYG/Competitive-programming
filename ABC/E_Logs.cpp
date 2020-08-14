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
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<double,int> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N,K;
int A[200000];

int cut(int X){
    int res=0;
    rep(i,N) res+=(A[i]-1)/X;
    return res; 
}

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    int l=0,  r=1000000000;
    while(r-l>1){
        int X=(l+r)/2;
        int cnt=cut(X);
        if(cnt<=K) r=X;
        else l=X;
    }

    int ans=r;
    cout<<ans<<endl;
}

/*
int N,K;
double A[200000];
double sum[200000];
int cnt[200000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    sort(A,A+N);

    repn(i,N) sum[i]+=sum[i-1]+A[i-1];
    cout<<setprecision(16)<<sum[N]<<endl;

    double m=sum[N]/K;

    rep(i,N){
        cnt[i]=1+(int)(A[i+1]/m)-(int)(A[i]/m);
        cout<<cnt[i]<<endl;
    }

    int ans=0;
    rep(i,N) ans=max(ans,(int)(A[i]/cnt[i]));

    cout<<ans<<endl;
}
*/