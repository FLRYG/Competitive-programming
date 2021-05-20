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
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int X,Y,N;
int t[301];
int h[301];

int main(){
    cin>>X>>Y>>N;
    repn(i,N) cin>>t[i]>>h[i];

    vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(X+1,vector<int>(Y+1,0)));
    repn(i,N) repn(j,X){
        dp[i][j][0]=dp[i-1][j][0];
        if(j>=t[i]) dp[i][j][0]=max(dp[i][j][0],dp[i][j-t[i]][0]+h[i]);
    }
    repn(i,N) repn(j,X) repn(k,Y){
        dp[i][j][k]=max(dp[i][j-1][k],dp[i][j][k-1]);
        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
        if(j+k>=t[i]){
            int kk=max(0,k-(t[i]-1));
            int jj=min(j-1,j-1+k-(t[i]-1));
            dp[i][j][k]=max(dp[i][j][k],dp[i-1][jj][kk]+h[i]);
        }
    }

    cout<<dp[N][X][Y]<<endl;
    
    return 0;
}