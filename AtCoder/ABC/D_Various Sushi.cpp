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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repn(i,n) for(ll i=1;i<=n;i++)
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

ll N,K;
ll t[100000];
ll d[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>t[i]>>d[i];

    vector<ll> sup(N+1,-1);
    rep(i,N) sup[t[i]]=max(sup[t[i]],d[i]);

    vector<ll> v1(1,0), v2(1,0);
    rep(i,N){
        if(d[i]==sup[t[i]]){
            v1.push_back(d[i]);
            sup[t[i]]=-1;
        }else{
            v2.push_back(d[i]);
        }
    }
    sort(v1.begin()+1,v1.end(),greater<>());
    sort(v2.begin()+1,v2.end(),greater<>());
    repn(i,v1.size()-1) v1[i]+=v1[i-1];
    repn(i,v2.size()-1) v2[i]+=v2[i-1];

    ll ans=0;
    rep(i,v1.size()){
        ll j=K-i;
        if(0<=j && j<v2.size()){
            ll res=i*i+v1[i]+v2[j];
            ans=max(ans,res);
        }
    }

    cout<<ans<<endl;
    
    return 0;
}