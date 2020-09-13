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

ll N;
ll x[200000];
ll y[200000];
ll b[2]={1,-1};

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i];

    ll ans=0;
    rep(i,2){
        rep(j,2){
            vector<ll> v(N);
            rep(k,N){
                v[k]+=x[k]*b[i];
                v[k]+=y[k]*b[j];
            }
            sort(v.begin(),v.end());
            ans=max(ans,v[N-1]-v[0]);
        }
    }

    cout<<ans<<endl;
}