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
ll a[100000];
ll b[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i]>>b[i];

    vector<int> id(N,0);
    iota(id.begin(),id.end(),0);

    sort(id.begin(),id.end(),[&](int i, int j){
        ll c=a[i]-b[i]<0?-1:1;
        ll d=a[j]-b[j]<0?-1:1;
        if(c==d && c==-1) return a[i]<a[j];
        else if(c==d && c==1) return b[i]>b[j];
        else return c<d;
    });

    // rep(i,N) cout<<i<<' '<<a[id[i]]<<' '<<b[id[i]]<<' '<<a[id[i]]-b[id[i]]<<endl;

    ll ans=0, T=0;
    rep(i,N){
        T+=a[id[i]];
        ans=max(ans,T);
        T-=b[id[i]];
    }

    cout<<ans<<endl;
    
    return 0;
}