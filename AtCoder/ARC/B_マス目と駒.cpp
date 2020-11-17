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
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int H,W;
char S[101][101];
bool dp[101][101];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>S[i][j];
    rep(i,H+1) S[i][W]='#';
    rep(j,W+1) S[H][j]='#';

    rep(i,H+1){
        rep(j,W+1){
            if(S[i][j]=='#') dp[i][j]=true;
        }
    }

    for(int i=H-1;i>=0;i--){
        for(int j=W-1;j>=0;j--){
            if(S[i][j]=='#') continue;
            if(dp[i+1][j] && dp[i+1][j+1] && dp[i][j+1]) dp[i][j]=false;
            else dp[i][j]=true;
        }
    }

    string ans;
    if(dp[0][0]) ans="First";
    else ans="Second";

    cout<<ans<<endl;
    
    return 0;
}