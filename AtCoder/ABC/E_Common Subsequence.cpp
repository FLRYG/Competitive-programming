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
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,M;
ll S[2001];
ll T[2001];

int main(){
    cin>>N>>M;
    repn(i,N) cin>>S[i];
    repn(i,M) cin>>T[i];

    vector<vector<ll>> dp(N+1,vector<ll>(M+1,0));
    rep(i,N+1) dp[i][0]=1;
    rep(j,M+1) dp[0][j]=1;
    repn(i,N) repn(j,M){
        if(S[i]==T[j]) dp[i][j]=dp[i-1][j]+dp[i][j-1];
        else dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        dp[i][j]%=MOD;
    }
    // rep(i,N+1){
    //     rep(j,M+1) cout<<dp[i][j]<<' ';
    //     cout<<endl;
    // }

    ll ans=(dp[N][M]+MOD)%MOD;
    cout<<ans<<endl;
    
    return 0;
}