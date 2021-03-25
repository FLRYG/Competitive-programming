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
ll const MOD=998244353;

ll N,S;
ll A[3001];

int main(){
    cin>>N>>S;
    repn(i,N) cin>>A[i];

    vector<vector<ll>> dp(N+1,vector<ll>(S+1,0));
    dp[0][0]=1;
    repn(i,N){
        rep(j,S+1){
            dp[i][j]+=2*dp[i-1][j];
            if(j>=A[i]) dp[i][j]+=dp[i-1][j-A[i]];
            dp[i][j]%=MOD;
            // cout<<dp[i][j]<<' ';
        }
        // cout<<endl;
    }

    cout<<dp[N][S]<<endl;
    
    return 0;
}

// ll N,S;
// ll A[3001];

// int main(){
//     cin>>N>>S;
//     repn(i,N) cin>>A[i];

//     vector<ll> cnt(3001,0);
//     repn(i,N) cnt[A[i]]++;

//     vector<vector<ll>> dp(3001,vector<ll>(S+1,0));
//     dp[0][0]=1;
//     repn(i,3000){
//         repn(j,S){
//             if(i<=j && j/i<=cnt[i]) dp[i][j]+=dp[i-1][j-i];
//             dp[i][j]+=dp[i-1][j];
//             dp[i][j]%=MOD;
//         }
//     }
//     repn(i,4){
//         repn(j,S){
//             cout<<dp[i][j]<<' ';
//         }
//         cout<<endl;
//     }

//     cout<<dp[3000][S]<<endl;
    
//     return 0;
// }