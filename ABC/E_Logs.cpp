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
typedef pair<double,int> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N,K;
double A[200000];
int cnt[200000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    priority_queue<P> q;
    rep(i,N) q.push(P(A[i],i));

    rep(i,K){
        P p=q.top(); q.pop();
        cnt[p.second]++;
        q.push(P(A[p.second]/(cnt[p.second]+1),p.second));
    }

    int ans=ceil(q.top().first);
    cout<<ans<<endl;
}

/*
ll N,K;
ll A[200000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    ll ans=0;
    rep(i,N) ans+=A[i];
    ans=(ans+1)/(K+1);

    cout<<ans<<endl;
}
*/