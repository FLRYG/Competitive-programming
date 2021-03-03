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
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int R[3000];

int main(){
    cin>>N;
    rep(i,N) cin>>R[i];

    vector<vector<int>> dp(2,vector<int>(N,0));
    dp[0][N-1]=1;
    dp[1][N-1]=1;
    for(int i=N-1;i>=0;i--){
        for(int j=i+1;j<N;j++){
            if(R[i]<R[j]) dp[1][i]=max(dp[1][i],dp[0][j]+1);
            if(R[i]>R[j]) dp[0][i]=max(dp[0][i],dp[1][j]+1);
        }
    }

    int ans=max(dp[0][0],dp[1][0]);
    if(ans<3) ans=0;

    cout<<ans<<endl;
    
    return 0;
}