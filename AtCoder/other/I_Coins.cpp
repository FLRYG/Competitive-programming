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

int N;
double p[3000];

int main(){
    cin>>N;
    repn(i,N) cin>>p[i];

    vector<vector<double>> dp(N+1,vector<double>(N+1,0));
    dp[0][0]=1;
    repn(i,N){
        rep(j,N+1){
            dp[i][j]=dp[i-1][j-1]*p[i]+dp[i-1][j]*(1-p[i]);
        }
    }

    double ans=0;
    for(int i=(N+1)/2;i<=N;i++) ans+=dp[N][i];

    cout<<setprecision(16)<<ans<<endl;
    
    return 0;
}