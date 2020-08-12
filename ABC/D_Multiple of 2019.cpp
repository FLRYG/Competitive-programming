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
//typedef pair<int,int> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=2019;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

string S;
ll N;
ll val[200000];
ll sum[200001];
ll cnt[2020];

int main(){
    cin>>S;
    N=S.size();

    ll ten=1;
    for(int i=N-1;i>=0;i--){
        val[i]=(S[i]-'0')*ten%MOD;
        ten*=10;
        ten%=MOD;
        //cout<<i<<' '<<val[i]<<endl;
    }//cout<<endl;
    for(int i=N-1;i>=0;i--){
        sum[i]=sum[i+1]+val[i];
        sum[i]%=MOD;
        //cout<<i<<' '<<sum[i]<<endl;
    }//cout<<endl;
    rep(i,N){
        cnt[sum[i]%MOD]++;
    }

    ll ans=cnt[0];
    rep(i,MOD+1){
        ans+=cnt[i]*(cnt[i]-1)/2;
        //if(cnt[i]>0) cout<<i<<' '<<cnt[i]<<endl;
    }

    cout<<ans<<endl;
}