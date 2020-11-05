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
int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N;
int NG[3];
int dp[301];

int main(){
    cin>>N;
    rep(i,3) cin>>NG[i];

    rep(i,3) dp[NG[i]]=INF;
    repn(i,N){
        if(dp[i]==INF) continue;
        int res=INF;
        if(i-1>=0 && dp[i-1]!=INF) res=min(res,dp[i-1]+1);
        if(i-2>=0 && dp[i-2]!=INF) res=min(res,dp[i-2]+1);
        if(i-3>=0 && dp[i-3]!=INF) res=min(res,dp[i-3]+1);
        dp[i]=res;
    }

    string ans="YES";
    if(dp[N]>100) ans="NO";

    cout<<ans<<endl;
}