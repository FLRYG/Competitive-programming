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

string S;

int main(){
    cin>>S;
    int N=S.size();

    vector<vector<int>> dp(N+1,vector<int>(N,0));
    for(int i=N-2;i>=0;i--){
        for(int j=N-1;j>i;j--){
            if(S[i]==S[j]) dp[i][j]=min(dp[i+1][j+1]+1,j-i);
        }
    }
    // rep(i,N-1){
    //     for(int j=i+1;j<N;j++) cout<<i<<','<<j<<": "<<dp[i][j]<<endl;
    // }

    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            
        }
    }

    return 0;
}