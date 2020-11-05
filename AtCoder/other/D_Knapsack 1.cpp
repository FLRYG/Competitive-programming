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

ll N,W;
ll w[101], v[101];
ll dp[101][100001];

int main(){
    cin>>N>>W;
    repn(i,N) cin>>w[i]>>v[i];

    repn(i,N){
        repn(j,W){
            if(j<w[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
        }
    }

    ll ans=0;
    repn(i,W) ans=max(ans,dp[N][i]);
    cout<<ans<<endl;
}