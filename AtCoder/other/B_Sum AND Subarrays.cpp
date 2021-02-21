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
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

ll N,K;
ll a[1001];

int main(){
    cin>>N>>K;
    repn(i,N) cin>>a[i];
    repn(i,N) a[i]+=a[i-1];

    vector<ll> val(0);
    repn(i,N){
        for(int j=i;j<=N;j++) val.push_back(a[j]-a[i-1]);
    }

    vector<ll> cnt(50);
    repr(e,val){
        // cout<<e<<endl;
        rep(i,50) cnt[i]+=e>>i&1;
    }

    ll ans=(1LL<<50)-1;
    rep(i,50){
        if(cnt[49-i]>=K){
            vector<ll> v;
            repr(e,val) if(e>>(49-i)&1) v.push_back(e);
            sort(v.begin(),v.end(),greater<>());
            rep(j,K) ans&=v[j];
            break;
        }
    }
    if(ans==(1LL<<50)-1) ans=0;

    cout<<ans<<endl;
    
    return 0;
}