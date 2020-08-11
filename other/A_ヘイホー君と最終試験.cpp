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
//typedef pair<ll,ll> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll N,K,M,R;
ll S[100];

int main(){
    cin>>N>>K>>M>>R;
    rep(i,N-1) cin>>S[i];

    sort(S,S+N-1,greater<>());

    ll ok=K*R;
    ll res=0;
    rep(i,K-1) res+=S[i];

    ll ans=ok-res;
    if(ans<=S[K-1]) ans=0;
    else if(ans>M) ans=-1;
    else if(ans<0) ans=0;

    cout<<ans<<endl;
}