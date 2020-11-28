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

int a,b,x,y;
int dp[2][105];

int main(){
    cin>>a>>b>>x>>y;

    if(a==b){
        cout<<x<<endl;
        return 0;
    }

    rep(i,2) rep(j,105) dp[i][j]=INF;

    int ans;
    if(a<b){
        dp[0][1]=0;
        dp[1][1]=x;
        repn(i,b-a){
            dp[0][i+1]=min(dp[0][i]+y,dp[1][i]+x);
            dp[1][i+1]=min(dp[1][i]+y,dp[0][i+1]+x);
        }
        ans=dp[1][b-a+1];
    }else{
        dp[1][1]=0;
        dp[0][1]=x;
        repn(i,a-b){
            dp[0][i+1]=min(dp[0][i]+y,dp[1][i]+x);
            dp[1][i+1]=min(dp[1][i]+y,dp[0][i+1]+x);
        }
        ans=dp[0][a-b+1];
    }

    cout<<ans<<endl;
    
    return 0;
}