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

ll N,M;
string S[1000];
ll C[1000];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>S[i]>>C[i];

    vector<ll> s(M,0);
    rep(i,M){
        rep(j,N) if(S[i][j]=='Y') s[i]|=1<<j;
    }

    vector<ll> dp(1<<N,LINF);
    dp[0]=0;
    rep(i,(1<<N)-1){
        rep(j,M){
            dp[i|s[j]]=min(dp[i|s[j]],dp[i]+C[j]);
        }
    }

    ll ans=dp[(1<<N)-1];
    if(ans==LINF) ans=-1;

    cout<<ans<<endl;
    
    return 0;
}