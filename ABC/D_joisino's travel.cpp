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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M,R;
int r[8];
vector<P> v[200000];
int table[]={0,1,2,3,4,5,6,7};

int main(){
    cin>>N>>M>>R;
    rep(i,R) cin>>r[i];
    rep(i,R) r[i]--;
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        v[a-1].push_back(P(b-1,c));
        v[b-1].push_back(P(a-1,c));
    }

    map<P,int> m;
    rep(s,R){
        vector<int> dis(N,INF);
        dis[r[s]]=0;
        priority_queue<P,vector<P>,greater<P>> q;
        q.push(P(0,r[s]));
        while(!q.empty()){
            P p=q.top(); q.pop();
            int from=p.second;
            if(dis[from]<p.first) continue;
            rep(i,v[from].size()){
                int to=v[from][i].first;
                int cost=v[from][i].second;
                if(dis[from]+cost<dis[to]){
                    dis[to]=dis[from]+cost;
                    q.push(P(dis[to],to));
                }
            }
        }
        //cout<<"start="<<r[s]<<' '; rep(i,N) cout<<dis[i]<<' '; cout<<endl;
        rep(i,R){
            m[P(r[s],r[i])]=dis[r[i]];
            m[P(r[i],r[s])]=dis[r[i]];
        }
    }

    int ans=INF;
    do{
        int res=0;
        rep(n,R-1){
            int i=table[n];
            int j=table[n+1];
            res+=m[P(r[i],r[j])];
        }
        //cout<<res<<endl;
        ans=min(ans,res);
    }while(next_permutation(table,table+R));

    cout<<ans<<endl;
}