#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
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
ll const MOD=1000000007;

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

ll N,K;
ll dp[100001];

int main(){
    cin>>N>>K;

    ll ans=0;
    for(int k=K;k>=1;k--){
        dp[k]=mpow(K/k,N);
        for(int i=2;i*k<=K;i++){
            dp[k]-=dp[i*k];
            dp[k]%=MOD;
        }
        ans+=k*dp[k];
        ans%=MOD;
    }
    ans=(ans+MOD)%MOD;
    //repn(i,K) cout<<i<<' '<<dp[i]<<endl;

    cout<<ans<<endl;
    
    return 0;
}