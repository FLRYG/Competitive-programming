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

ll A,B,C,D;

int main(){
    cin>>A>>B>>C>>D;

    vector<vector<ll>> dp(C+1,vector<ll>(D+1,0));
    dp[A][B]=1;
    for(ll i=A;i<=C;i++){
        for(ll j=B;j<=D;j++){
            if(i==A && j==B) continue;
            // if(A<i && B<j) dp[i][j]=dp[i-1][j-1]*((i+j-1)*(i+j-2)/2)%MOD;
            // else if(A<i) dp[i][j]=dp[i-1][j]*j%MOD;
            // else if(B<j) dp[i][j]=dp[i][j-1]*i%MOD;
            dp[i][j]+=dp[i-1][j]*j%MOD;
            dp[i][j]+=dp[i][j-1]*i%MOD;
            dp[i][j]+=MOD-(i-1)*(j-1)%MOD;
            dp[i][j]%=MOD;
        }
    }

    cout<<dp[C][D]<<endl;
    
    return 0;
}