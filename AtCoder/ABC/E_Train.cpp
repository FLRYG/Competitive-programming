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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
double const PI=3.141592653589793;
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

ll N,M,X,Y;

int main(){
    cin>>N>>M>>X>>Y;
    X--, Y--;
    vector<vector<PP>> G(N,vector<PP>());
    rep(i,M){
        int a,b,t,k;
        cin>>a>>b>>t>>k;
        G[a-1].push_back(PP(t,P(b-1,k)));
        G[b-1].push_back(PP(t,P(a-1,k)));
    }
    
    vector<ll> cost(N,LINF);
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(P(0,X));
    while(!q.empty()){
        P p=q.top(); q.pop();
        if(p.first>=cost[p.second]) continue;
        cost[p.second]=p.first;
        repr(e,G[p.second]){
            ll k=e.second.second;
            ll c=p.first+e.first+((p.first+k-1)/k*k-p.first);
            q.push(P(c,e.second.first));
        }
    }
    ll ans=cost[Y];
    if(ans==LINF) ans=-1;

    cout<<ans<<endl;
    
    return 0;
}