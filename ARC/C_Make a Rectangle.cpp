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
ll A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    map<ll,ll> m;
    rep(i,N) m[A[i]]++;

    ll x=0,y=0;
    repr(e,m){
        if(4<=e.second){
            x=y=e.first;
        }else if(2<=e.second){
            x=y;
            y=e.first;
        }
    }

    ll ans=x*y;
    cout<<ans<<endl;
}