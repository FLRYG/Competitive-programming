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

ll N,M;
ll A[1000];
ll B[1000];
ll dp[1000+1][1000+1];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];

    if(N>M) swap(A,B);
    
    return 0;
}

// ll N,M;
// ll A[1000];
// ll B[1000];
// ll dp[1000+1][1000+1];

// int main(){
//     cin>>N>>M;
//     rep(i,N) cin>>A[i];
//     rep(i,M) cin>>B[i];

//     for(int i=0;i<N;i++){
//         for(int j=0;j<M;j++){
//             if(A[i]==B[j]){
//                 dp[i+1][j+1]=dp[i][j]+1;
//             }else{
//                 dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
//             }
//         }
//     }

//     ll ans=abs(N-M)+2*(min(N,M)-dp[N][M]);
//     cout<<ans<<endl;
    
//     return 0;
// }