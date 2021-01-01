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
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll I[]={1,1,0,-1,-1,-1,0,1};
ll J[]={0,1,1,1,0,-1,-1,-1};

ll H,W,N;
ll a[100000];
ll b[100000];

int main(){
    cin>>H>>W>>N;
    rep(i,N) cin>>a[i]>>b[i];

    map<P,ll> m;
    rep(i,N){
        m[P(a[i],b[i])]++;
        rep(k,8){
            ll x=a[i]+I[k];
            ll y=b[i]+J[k];
            if(1<=x && x<=H && 1<=y && y<=W){
                m[P(x,y)]++;
            }
        }
    }

    vector<ll> ans(10,0);
    ans[0]=(H-2)*(W-2);
    repr(e,m){
        ll x=e.first.first;
        ll y=e.first.second;
        if(1<x && x<H && 1<y && y<W){
            ans[e.second]++;
            ans[0]--;
        }
    }

    rep(i,10) cout<<ans[i]<<endl;
    
    return 0;
}