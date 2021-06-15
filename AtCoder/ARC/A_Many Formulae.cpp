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

ll N;
ll A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    vector<ll> p(N+1,0), m(N+1,0);
    p[0]=1;
    repn(i,N){
       p[i]=p[i-1]+m[i-1];
       m[i]=p[i-1];
       p[i]%=MOD;
    }

    ll ans=A[0]*(p[N-1]+m[N-1])%MOD;
    // cout<<ans<<endl;
    repn(i,N-1){
        ans+=A[i]*(p[N-i-1]+m[N-i-1])%MOD*(p[i-1]+m[i-1])%MOD;
        ans-=A[i]*(p[N-i-1])%MOD*(p[i-1])%MOD;
        ans%=MOD;
    }
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
    
    return 0;
}