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
typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll K,N,M;
ll A[100000];

int main(){
    cin>>K>>N>>M;
    rep(i,K) cin>>A[i];

    rep(i,K) A[i]*=M;

    vector<ll> B(K,0);
    rep(i,K) B[i]=A[i]/N*N;

    ll sumA=0, sumB=0;
    rep(i,K) sumA+=A[i];
    rep(i,K) sumB+=B[i];
    ll e=(sumA-sumB)/N;

    priority_queue<P,vector<P>,greater<P>> q;
    rep(i,K) q.push({B[i]-A[i],i});
    while(e--){
        P p=q.top(); q.pop();
        p.first+=N;
        q.push(p);
    }

    rep(i,K){
        P p=q.top(); q.pop();
        B[p.second]=(p.first+A[p.second])/N;
    }

    rep(i,K) cout<<B[i]<<' '; cout<<endl;
    
    return 0;
}