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
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int n,m;
int s,t;

int main(){
    cin>>n>>m>>s>>t;
    s--, t--;
    vector<P> G[1000];
    rep(i,m){
        int x,y,d;
        cin>>x>>y>>d;
        x--, y--;
        G[x].push_back(P(d,y));
        G[y].push_back(P(d,x));
    }

    vector<int> sdist(n,INF);
    sdist[s]=0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(P(0,s));
    while(!q.empty()){
        P p=q.top(); q.pop();
        int v=p.second;
        if(p.first>sdist[v]) continue;
        rep(i,G[v].size()){
            P e=G[v][i];
            if(sdist[v]+e.first<sdist[e.second]){
                sdist[e.second]=sdist[v]+e.first;
                q.push(P(sdist[e.second],e.second));
            }
        }
    }

    vector<int> tdist(n,INF);
    tdist[t]=0;
    q.push(P(0,t));
    while(!q.empty()){
        P p=q.top(); q.pop();
        int v=p.second;
        if(p.first>tdist[v]) continue;
        rep(i,G[v].size()){
            P e=G[v][i];
            if(tdist[v]+e.first<tdist[e.second]){
                tdist[e.second]=tdist[v]+e.first;
                q.push(P(tdist[e.second],e.second));
            }
        }
    }

    int ans=-1;
    rep(i,n){
        //cout<<i+1<<' '<<sdist[i]<<' '<<tdist[i]<<endl;
        if(sdist[i]==INF) continue;
        if(sdist[i]==tdist[i]) ans=i+1;
    }

    cout<<ans<<endl;
}