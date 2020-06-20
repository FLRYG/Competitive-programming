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
    fill(dp[0],dp[0]+N*1000+1,1001001001);
    dp[0][0]=0;

    repn(i,N){
        repn(j,N*1000){
            if(j<v[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=min(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
        }
    }

    ll ans=0;
    repn(i,N*1000+1) ans=max(a
    cout<<ans<<endl;
}