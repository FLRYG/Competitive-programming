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
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;

string S;
ll dp[100001][3];

int main(){
    cin>>S;

    for(int i=S.size()-1;i>=0;i--){
        dp[i][0]=dp[i+1][0];
        dp[i][1]=dp[i+1][1];
        dp[i][2]=dp[i+1][2];
        if(S[i]=='A') dp[i][0]+=dp[i][1];
        if(S[i]=='B') dp[i][1]+=dp[i][2];
        if(S[i]=='C') dp[i][2]++;
        if(S[i]=='?'){
            dp[i][2]++;
            dp[i][1]+=dp[i][2];
            dp[i][0]+=dp[i][1];
        }
        //rep(j,3) dp[i][j]%=MOD;
    }

    ll ans=dp[0][0];
    cout<<ans<<endl;
}