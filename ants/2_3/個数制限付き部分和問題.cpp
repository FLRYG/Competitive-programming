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

int N,K;
int a[101];
int m[101];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>a[i];
    repn(i,N) cin>>m[i];

    // 配列の再利用可能
    vector<vector<int>> dp(N+1,vector<int>(K+1));
    repn(i,N) dp[i][0]=m[i];
    repn(j,K) dp[0][j]=-1;
    repn(i,N){
        repn(j,K){
            if(dp[i-1][j]>=0) dp[i][j]=m[i];
            else if(j>=a[i]) dp[i][j]=max(dp[i][j-a[i]]-1,-1);
            else dp[i][j]=-1;
        }
    }

    string ans="No";
    if(dp[N][K]>=0) ans="Yes";

    cout<<ans<<endl;
}