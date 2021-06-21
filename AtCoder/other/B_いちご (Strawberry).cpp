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
typedef pair<ll,ll> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N;
P p[100001];

int main(){
    cin>>N;
    repn(i,N) cin>>p[i].first>>p[i].second;

    sort(p+1,p+N+1);

    ll ans=p[N].first;
    rep(i,N){
        if(ans<p[N-i].second) ans=p[N-i].second;
        ans+=p[N-i].first-p[N-i-1].first;
    }

    cout<<ans<<endl;
    
    return 0;
}