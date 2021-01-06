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
typedef pair<ll,ll> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,M,S,T;

void dijkstra(vector<vector<P>> &G, vector<ll> &cost, ll s){
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P(0,s));
    while(!que.empty()){
        P p=que.top(); que.pop();
        if(p.first>=cost[p.second]) continue;
        cost[p.second]=p.first;
        repr(e,G[p.second]){
            if(cost[p.second]+e.second>=cost[e.first]) continue;
            que.push(P(cost[p.second]+e.second,e.first));
        }
    }
}

int main(){
    cin>>N>>M>>S>>T;
    S--;
    T--;
    vector<vector<P>> A(N,vector<P>());
    vector<vector<P>> B(N,vector<P>());
    ll u,v,a,b;
    rep(i,M){
        cin>>u>>v>>a>>b;
        u--;
        v--;
        A[u].push_back(P(v,a));
        A[v].push_back(P(u,a));
        B[u].push_back(P(v,b));
        B[v].push_back(P(u,b));
    }

    vector<ll> costS(N,LINF);
    vector<ll> costT(N,LINF);
    dijkstra(A,costS,S);
    dijkstra(B,costT,T);

    vector<ll> sum(N,0);
    map<ll,ll> m;
    vector<ll> cost(N);
    rep(i,N){
        sum[i]=costS[i]+costT[i];
        cost[i]=sum[i];
        m[sum[i]]++;
    }
    sort(cost.begin(),cost.end());

    ll k=0;
    ll ans=1e15;
    rep(i,N){
        while(m[cost[k]]<=0) k++;
        cout<<ans-cost[k]<<endl;
        m[sum[i]]--;
    }
    
    return 0;
}