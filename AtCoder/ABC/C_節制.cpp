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

ll N,H,A,B,C,D,E;

int main(){
    cin>>N>>H>>A>>B>>C>>D>>E;

    ll ans=LINF;
    rep(i,N+1){
        ll x=H+B*i;
        ll l=-1, r=N-i+1;
        while(r-l>1){
            ll m=(l+r)/2;
            ll y=x+D*m-E*(N-i-m);
            if(y>0) r=m;
            else l=m;
        }
        if(r==N-i+1) continue;
        // cout<<i<<' '<<r<<' '<<N-i-r<<' '<<x+D*r<<' '<<E*(N-i-r)<<' '<<A*i+C*r<<endl;
        ans=min(ans,A*i+C*r);
    }

    cout<<ans<<endl;
    
    return 0;
}