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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repn(i,n) for(ll i=1;i<=n;i++)
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

ll N,K;

int main(){
    cin>>N>>K;

    vector<ll> v(100000,0);
    rep(i,100000){
        ll n=i, z=i;
        while(n>0){
            z+=n%10;
            n/=10;
        }
        z%=100000;
        v[i]=z;
    }

    vector<ll> num(100000,0);
    map<ll,ll> ma;
    num[0]=N;
    ma[N]=0;
    ll n=N, cnt=0;
    ll m, q;
    rep(i,100000){
        if(v[n]!=N && ma[v[n]]==0){
            ma[v[n]]=++cnt;
            num[cnt]=v[n];
        }else{
            q=ma[v[n]];
            m=cnt-ma[v[n]];
        }
    }

    ll ans;
    if(K<q) ans=num[K];
    else ans=num[q+(K-q)%m];

    cout<<ans<<endl;
    
    return 0;
}