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
typedef pair<ll,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,K;
int A[200000];
int B[200000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i]>>B[i];

    priority_queue<IP> q;
    rep(i,N) q.push({B[i],{1,i}});

    ll ans=0;
    rep(i,K){
        IP p=q.top(); q.pop();
        ans+=p.first;
        if(p.second.first) q.push({A[p.second.second]-p.first,{0,0}});
    }

    cout<<ans<<endl;
    
    return 0;
}