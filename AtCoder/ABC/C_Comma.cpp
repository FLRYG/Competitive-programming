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

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1);
    return mpow(x*x,n/2);
}

ll N;

int main(){
    cin>>N;

    int d=0;
    ll n=N;
    while(n>0){
        n/=10;
        d++;
    }

    ll t=0;
    ll ans=0;
    while(N>=mpow(10,(t+1)*3)){
        ans+=t*(mpow(10,(t+1)*3)-mpow(10,t*3));
        t++;
    }
    ans+=t*(N-mpow(10,t*3)+1);

    cout<<ans<<endl;
    
    return 0;
}