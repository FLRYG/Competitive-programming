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

ll n,m;
ll x[100001];
ll y[100001];

int main(){
    cin>>n>>m;
    repn(i,n) cin>>x[i];
    repn(i,m) cin>>y[i];

    ll X=0, Y=0;
    repn(i,n-1){
        X+=i*(n-i)%MOD*(x[i+1]-x[i])%MOD;
        X%=MOD;
    }
    repn(j,m-1){
        Y+=j*(m-j)%MOD*(y[j+1]-y[j])%MOD;
        Y%=MOD;
    }

    ll ans=X*Y%MOD;

    cout<<ans<<endl;
    
    return 0;
}