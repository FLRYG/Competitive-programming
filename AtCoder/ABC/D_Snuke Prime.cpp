#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,C;
ll a[200000];
ll b[200000];
ll c[200000];

int main(){
    cin>>N>>C;
    rep(i,N) cin>>a[i]>>b[i]>>c[i];

    map<ll,ll> m;
    rep(i,N){
        m[a[i]]+=c[i];
        m[b[i]+1]-=c[i];
    }

    for(auto i1=m.begin(),i2=++m.begin();i2!=m.end();i1++,i2++){
        (*i2).second+=(*i1).second;
    }

    // repr(e,m) cout<<e.first<<' '<<e.second<<endl;

    ll ans=0;
    for(auto i1=m.begin(),i2=++m.begin();i2!=m.end();i1++,i2++){
        ll k=(*i2).first-(*i1).first;
        if((*i1).second>=C) ans+=k*C;
        else ans+=k*((*i1).second);
    }

    cout<<ans<<endl;
    
    return 0;
}