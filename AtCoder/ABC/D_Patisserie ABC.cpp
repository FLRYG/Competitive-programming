#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
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
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll b[]={1,-1};

ll N,M;
ll x[1000];
ll y[1000];
ll z[1000];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>x[i]>>y[i]>>z[i];

    ll ans=0;
    rep(i,2){
        rep(j,2){
            rep(k,2){
                vector<ll> v(N,0);
                rep(l,N){
                    v[l]+=x[l]*b[i];
                    v[l]+=y[l]*b[j];
                    v[l]+=z[l]*b[k];
                }
                sort(v.begin(),v.end(),greater<>());
                ll res=0;
                rep(l,M) res+=v[l];
                ans=max(ans,res);
            }
        }
    }

    cout<<ans<<endl;
}