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

int N,X;
int w[32];

int main(){
    cin>>N>>X;
    rep(i,N) cin>>w[i];

    map<int,ll> m1,m2;
    rep(i,1<<(N/2)){
        int W=0;
        rep(j,N/2) if(i>>j&1) W+=w[j];
        m1[W]++;
    }
    rep(i,1<<((N+1)/2)){
        int W=0;
        rep(j,(N+1)/2) if(i>>j&1) W+=w[j+N/2];
        m2[W]++;
    }

    ll ans=0;
    repr(e,m1) ans+=e.second*(m2[X-e.first]);

    cout<<ans<<endl;
    
    return 0;
}