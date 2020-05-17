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
vector<int> e[100001];
int ans[100001];
queue<P> que;

void bfs(int now,int parent){
    repr(x,e[now]){
        if(x==parent) continue;
        if(x!=0) continue;
    }
}

int main(){
    cin>>N>>M;
    repn(i,M){
        int a,b;
        cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    que.push(P(1,0));
    while(!que.empty()){
        P p=que.front();
        que.pop();
        int now=p.first, parent=p.second;
        rep(i,e[now].size()){
            if(e[now][i]==parent){
                continue;
            }
            if(ans[e[now][i]]!=0){
                continue;
            }
            que.push(P(e[now][i],now));
            ans[e[now][i]]=now;
        }
    }

    cout<<"Yes"<<endl;
    repn(i,N-1) cout<<ans[i+1]<<endl;
}