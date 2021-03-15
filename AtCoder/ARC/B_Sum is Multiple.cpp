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

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

ll N;

int main(){
    cin>>N;

    N*=2;
    ll ans=LINF;
    for(ll i=1;i*i<=N;i++){
        if(N%i!=0) continue;
        ll n1=i, n2=N/i;
        if(gcd(n1,n2)!=1) continue;
        ll x,y;
        extGCD(n1,n2,x,y);
        // cout<<n1<<"*"<<x<<"+"<<n2<<"*"<<y<<endl;
        // cout<<n1*x<<' '<<n2*y<<endl;
        if(x<0) ans=min(ans,-n1*x);
        if(y<0) ans=min(ans,-n2*y);
    }

    if(ans==LINF) ans=N-1;

    cout<<ans<<endl;
    
    return 0;
}