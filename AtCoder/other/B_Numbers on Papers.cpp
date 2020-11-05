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
ll const MOD=1000000007;

ll N,K;
ll v[100][10000];

int main(){
    cin>>N>>K;
    rep(i,N) rep(j,K) cin>>v[i][j];

    vector<ll> dp(K+1,1);
    dp[0]=0;
    repn(i,K) dp[i]+=dp[i-1];
        // rep(j,K+1) cout<<dp[j]<<' ';cout<<endl;
    repn(n,N-1){
        ll i=0;
        vector<int> memo(K+1);
        rep(j,K){
            while(i<K && v[n-1][i]<=v[n][j]) i++;
            memo[j+1]=dp[i];
            memo[j+1]%=MOD;
        }
        repn(j,K){
            memo[j]+=memo[j-1];
            memo[j]%=MOD;
        }
        rep(j,K+1) dp[j]=memo[j];
        // rep(j,K+1) cout<<dp[j]<<' ';cout<<endl;
    }

    cout<<dp[K]<<endl;
}