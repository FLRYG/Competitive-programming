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

ll msqrt(ll x){
    ll l=0 ,r=x;
    while(r-l>1){
        // cout<<l<<' '<<r<<endl;
        ll m=(l+r)/2;
        if(m<x/m) l=m;
        else r=m;
    }
    return r;
}

ll R,X,Y;

int main(){
    cin>>R>>X>>Y;
    X*=10000;
    Y*=10000;
    R*=10000;

    // cout<<msqrt(X*X+Y*Y)<<endl;
    ll ans=(msqrt(X*X+Y*Y)+R-1)/R;
    if(msqrt(X*X+Y*Y)<R) ans=2;

    cout<<ans<<endl;
    
    return 0;
}