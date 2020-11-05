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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=998244353;

ll N,K;
ll L[10],R[10];

int main(){
    cin>>N>>K;
    rep(i,K) cin>>L[i]>>R[i];

    vector<ll> dp(N+1,0);
    dp[1]=1;
    vector<ll> sum(N+1,0);
    repn(i,N){
        rep(j,K){
            ll l=max((ll)0,i-R[j]-1);
            ll r=max((ll)0,i-L[j]);
            dp[i]+=sum[r]-sum[l];
            dp[i]%=MOD;
        }
        sum[i]+=sum[i-1]+dp[i];
        sum[i]%=MOD;
    }
    //repn(i,N) cout<<dp[i]<<' ';cout<<endl;

    ll ans=(dp[N]+MOD)%MOD;
    cout<<ans<<endl;
}