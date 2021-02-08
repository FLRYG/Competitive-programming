#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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

ll N,K;
ll a[101];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>a[i];

    if(K==0){
        cout<<1<<endl;
        return 0;
    }

    vector<vector<ll>> dp(N+1,vector<ll>(K+1,0));
    rep(i,N+1) dp[i][0]=1;
    repn(j,K) dp[0][j]+=dp[0][j-1];
    repn(i,N){
        repn(j,K){
            if(j-a[i]-1>=0) dp[i][j]+=dp[i-1][j]-dp[i-1][j-a[i]-1];
            else dp[i][j]+=dp[i-1][j];
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=MOD;
        }
    }

    // rep(j,K+1){rep(i,N+1){cout<<dp[i][j]<<' ';}cout<<endl;}

    ll ans=dp[N][K]-dp[N][K-1];
    if(ans<0) ans+=MOD;
    cout<<ans<<endl;

    return 0;
}