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
    vector<P> v[1000];
    rep(i,m){
        int x,y,d;
        cin>>x>>y>>d;
        x--, y--;
        v[x].push_back(P(d,y));
        v[y].push_back(P(d,x));
    }

    vector<int> sdist(n,INF);
    sdist[s]=0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(P(0,s));
    while(!q.empty()){
        P p=q.top(); q.pop();
        if(p.first>sdist[p.second]) continue;
        repr(e,v[p.second]){
            if(sdist[p.second]+e.first<sdist[e.second]){
                sdist[e.second]=sdist[p.second]+e.first;
                q.push(P(sdist[e.],e.second));
            }
        }
    }
    rep(i,n){
        cout<<i+1<<' '<<sdist[i]<<endl;
    }

    vector<int> tdist(n,INF);
    tdist[t]=0;
    q.push(P(0,t));
    while(!q.empty()){
        P p=q.top(); q.pop();
        if(p.first>tdist[p.second]) continue;
        repr(e,v[p.second]){
            if(p.first+e.first<tdist[e.second]){
                q.push(P(p.first+e.first,e.second));
                tdist[e.second]=p.second+e.first;
            }
        }
    }
    cout<<endl;
    rep(i,n){
        cout<<i+1<<' '<<tdist[i]<<endl;
    }

    int ans=-1;
    rep(i,n){
        if(sdist[i]==tdist[i]) ans=i+1;
    }

    cout<<ans<<endl;
}