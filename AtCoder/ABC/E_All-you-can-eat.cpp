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

int N,T;
int A[3001];
int B[3001];

int main(){
    cin>>N>>T;
    rep(i,N) cin>>A[i]>>B[i];
    vector<int> id(N,0);
    iota(id.begin(),id.end(),0);
    sort(id.begin(),id.end(),[&](int i, int j){ return A[i]<A[j]; });

    vector<vector<int>> dp(N+1,vector<int>(T,0));
    int ans=0;
    repn(i,N){
        rep(j,T){
            dp[i][j]=dp[i-1][j];
            ans=max(ans,dp[i][j]+B[id[i-1]]);
            if(0<=j-A[id[i-1]]) dp[i][j]=max(dp[i][j],dp[i-1][j-A[id[i-1]]]+B[id[i-1]]);
        }
    }

    cout<<ans<<endl;
    
    return 0;
}