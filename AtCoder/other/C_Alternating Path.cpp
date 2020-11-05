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

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};
int H,W;
string S[400];
int chk[400][400];

int main(){
    cin>>H>>W;
    rep(i,H) cin>>S[i];

    ll ans=0;
    rep(i,H){
        rep(j,W){
            if(S[i][j]=='.') continue;
            ll b=0, w=0;
            queue<P> q;
            q.push(P(i,j));
            while(!q.empty()){
                P p=q.front(); q.pop();
                if(chk[p.first][p.second]==1) continue;
                //cout<<p.first<<' '<<p.second<<endl;
                chk[p.first][p.second]=1;
                if(S[p.first][p.second]=='#') b++;
                else w++;
                rep(k,4){
                    int x=p.first+I[k];
                    int y=p.second+J[k];
                    if(0<=x && x<H && 0<=y && y<W && chk[x][y]==0
                    && S[p.first][p.second]!=S[x][y]){
                        q.push(P(x,y));
                    }
                }
            }
            //cout<<"b="<<b<<" w="<<w<<endl;
            ans+=b*w;
        }
    }

    cout<<ans<<endl;
}