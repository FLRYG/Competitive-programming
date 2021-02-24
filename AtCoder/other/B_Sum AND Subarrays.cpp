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

ll f(vector<ll> &val, ll n){
    vector<ll> cnt(n);
    repr(e,val) rep(i,n) cnt[i]+=e>>i&1;
    ll res=0;
    rep(i,n){
        if(cnt[n-i-1]>=K){
            vector<ll> v;
            repr(e,val) if(e>>(n-i-1)&1) v.push_back(e);
            res+=f(v,n-i-1);
            res+=1<<(n-i-1);
            break;
        }
    }
    return res;
}

int main(){
    cin>>N>>K;
    repn(i,N) cin>>a[i];
    repn(i,N) a[i]+=a[i-1];

    vector<ll> val(0);
    repn(i,N){
        for(int j=i;j<=N;j++) val.push_back(a[j]-a[i-1]);
    }

    ll ans=f(val,50);

    cout<<ans<<endl;
    
    return 0;
}