#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,M;
ll A[200000];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>A[i];
    vector<vector<ll>> G(N,vector<ll>());
    rep(i,M){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        G[x].push_back(y);
    }

    vector<ll> maxi(N,0);
    for(int i=N-1;i>=0;i--){
        repr(to,G[i]){
            maxi[i]=max(maxi[i],max(A[to],maxi[to]));
        }
    }
    //rep(i,N) cout<<i<<' '<<maxi[i]<<endl;

    ll ans=-LINF;
    rep(i,N){
        if(G[i].size()==0) continue;
        ans=max(ans,maxi[i]-A[i]);
    }

    cout<<ans<<endl;
    
    return 0;
}