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

ll N;
ll X[200000];
ll C[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>X[i]>>C[i];

    vector<int> cnt(N+1,0);
    rep(i,N) cnt[C[i]]++;

    int n=1;
    vector<int> num(N+1,-1);
    repn(i,N) if(cnt[i]) num[i]=n++;

    vector<ll> mini(n+1,LINF);
    vector<ll> maxi(n+1,-LINF);
    mini[0]=0;
    maxi[0]=0;
    rep(i,N) mini[num[C[i]]]=min(mini[num[C[i]]],X[i]);
    rep(i,N) maxi[num[C[i]]]=max(maxi[num[C[i]]],X[i]);
    mini[n]=0;
    maxi[n]=0;
    // repr(e,mini) cout<<e<<' '; cout<<endl;
    // repr(e,maxi) cout<<e<<' '; cout<<endl;

    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    for(int i=n-1;i>=0;i--){
        dp[i][0]+=maxi[i]-mini[i];
        dp[i][0]+=min(abs(maxi[i]-mini[i+1])+dp[i+1][0],abs(maxi[i]-maxi[i+1])+dp[i+1][1]);
        dp[i][1]+=maxi[i]-mini[i];
        dp[i][1]+=min(abs(mini[i]-mini[i+1])+dp[i+1][0],abs(mini[i]-maxi[i+1])+dp[i+1][1]);
    }
    // rep(i,n+1) cout<<dp[i][0]<<' '; cout<<endl;
    // rep(i,n+1) cout<<dp[i][1]<<' '; cout<<endl;

    ll ans=min(dp[0][0],dp[0][1]);

    cout<<ans<<endl;
    
    return 0;
}