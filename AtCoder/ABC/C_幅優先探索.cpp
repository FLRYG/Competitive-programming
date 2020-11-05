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

int a[]={1,0,-1,0};
int b[]={0,1,0,-1};

int R,C;
int sy,sx;
int gy,gx;
char c[51][51];
int G[51][51];

int main(){
    cin>>R>>C;
    cin>>sy>>sx>>gy>>gx;
    repn(i,R) repn(j,C) cin>>c[i][j];
    rep(i,R) fill(G[i]+1,G[i]+1+C,-1);

    queue<P> que;
    que.push(P(sy,sx));
    G[sy][sx]=0;
    while(!que.empty()){
        P p=que.front();
        que.pop();
        rep(i,4){
            int y=p.first+b[i];
            int x=p.second+a[i];
            if(c[y][x]=='.' && G[y][x]==-1){
                G[y][x]=G[p.first][p.second]+1;
                que.push(P(y,x));
            }
        }
    }

    int ans=G[gy][gx];
    cout<<ans<<endl;
}