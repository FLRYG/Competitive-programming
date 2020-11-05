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
typedef pair<int,int> P;

int N,M;
vector<P> G[301];
int T[301];

int main(){
    cin>>N>>M;
    rep(i,M){
        int a,b,t;
        cin>>a>>b>>t;
        G[a].push_back(P(b,t));
        G[b].push_back(P(a,t));
    }

    repn(i,N){
        int time[301];
        fill(time,time+301,1001001001);
        queue<P> q;
        time[i]=0;
        q.push(P(i,0));
        while(!q.empty()){
            P p=q.front();
            q.pop();
            int from=p.first, t=p.second;
            rep(j,G[from].size()){
                int to=G[from][j].first;
                if(t+G[from][j].second<time[to]){
                    time[to]=t+G[from][j].second;
                    q.push(P(to,time[to]));
                }
            }
        }
        int res=0;
        repn(i,N) if(time[i]>res) res=time[i];
        T[i]=res;
    }

    int ans=1001001001;
    repn(i,N) if(T[i]<ans) ans=T[i];
    cout<<ans<<endl;
}