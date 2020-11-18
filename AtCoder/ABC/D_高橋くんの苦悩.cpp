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

int W,N,K;
int A[51];
int B[51];
int dp[51][10001][51];

int main(){
    cin>>W>>N>>K;
    repn(i,N) cin>>A[i]>>B[i];

    repn(i,N){
        repn(j,W){
            repn(k,K){
                dp[i][j][k]=dp[i-1][j][k];
                if(j>=A[i]) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-A[i]][k-1]+B[i]);
            }
        }
    }

    cout<<dp[N][W][K]<<endl;
    
    return 0;
}