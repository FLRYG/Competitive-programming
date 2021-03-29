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

int N,M;
int S[2000];
int T[2000];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>S[i];
    rep(i,M) cin>>T[i];

    vector<vector<int>> dp(N+1,vector<int>(M+1,0));
    for(int i=N-1;i>=0;i--){
        for(int j=M-1;j>=0;j--){
            if(S[i]==T[j]) dp[i][j]=dp[i+1][j+1]*
        }
    }
    
    return 0;
}