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
ll a[300000];

int main(){
    cin>>N;
    rep(i,3*N) cin>>a[i];

    vector<ll> befsum(N+1,0);
    priority_queue<ll,vector<ll>,greater<ll>> befq;
    rep(i,N){
        befsum[0]+=a[i];
        befq.push(a[i]);
    }
    rep(i,N){
        if(befq.top()<a[N+i]){
            befsum[i+1]=befsum[i]-befq.top()+a[N+i];
            befq.pop();
            befq.push(a[N+i]);
        }else{
            befsum[i+1]=befsum[i];
        }
    }

    vector<ll> aftsum(N+1,0);
    priority_queue<ll> aftq;
    rep(i,N){
        aftsum[N]+=a[2*N+i];
        aftq.push(a[2*N+i]);j
    }
    for(int i=N-1;i>=0;i--){
        if(aftq.top()>a[N+i]){
            aftsum[i]=aftsum[i+1]-aftq.top()+a[N+i];
            aftq.pop();
            aftq.push(a[N+i]);
        }else{
            aftsum[i]=aftsum[i+1];
        }
    }

    ll ans=-LINF;
    rep(i,N+1){
        // cout<<befsum[i]<<' '<<aftsum[i]<<endl;
        ans=max(ans,befsum[i]-aftsum[i]);
    }

    cout<<ans<<endl;
    
    return 0;
}