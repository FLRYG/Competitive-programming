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

ll N;
ll a[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    ll l=0, r=1;
    ll ans=0;
    rep(i,N-1){
        if(a[i]>=a[i+1]){
            ll n=r-l;
            ans+=n*(n+1)/2;
            l=r;
        }
        r++;
    }
    ll n=r-l;
    ans+=n*(n+1)/2;

    cout<<ans<<endl;
}