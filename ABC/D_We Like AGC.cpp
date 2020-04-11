#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;

int N;
ll dp[101][5];

void init(){
    rep(i,4){
        dp[1][i]=1;
    }
    dp[1][4]=4;
    rep(i,4){
        dp[2][i]=4;
    }
    dp[2][4]=16;
}

int main(){
    cin>>N;

    init();

    for(int i=3;i<=N;i++){
        dp[i][0]=dp[i-1][4]%MOD;
        dp[i][1]=(dp[i-1][4]-dp[i-2][0]-dp[i-2][2]-dp[i-3][0]*3)%MOD;
        dp[i][2]=(dp[i-1][4]-dp[i-2][0])%MOD;
        dp[i][3]=dp[i-1][4]%MOD;
        dp[i][4]=(dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3])%MOD;
        if(dp[i][4]<0) dp[i][4]+=MOD;
    }

    ll ans=dp[N][4]>=0?dp[N][4]:dp[N][4]+MOD;
    cout<<ans<<endl;
}