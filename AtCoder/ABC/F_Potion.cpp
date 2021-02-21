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
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

ll N,X;
ll A[101];

int main(){
    cin>>N>>X;
    repn(i,N) cin>>A[i];
    sort(A+1,A+N+1);

    vector<vector<ll>> dp(N+1,vector<ll>(N+1));
    dp[0][0]=1;
    repn(i,N){
        repn(j,N){
            if(j>=A[i]) rep(k,i){
                dp[i][j]=max(dp[i][j],dp[k][j-A[i]]);
            }
            rep(k,i) dp[i][j]=max(dp[i][j],dp[i][j]);
        }
    }

    ll ans=LINF;
    rep(i,N+1){
        if(dp[N][i]==0) continue;
        if(X-dp[N][i])
    }
    
    return 0;
}