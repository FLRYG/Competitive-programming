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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int H,W;
char c[500][500];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>c[i][j];
    P s,g;
    rep(i,H) rep(j,W){
        if(c[i][j]=='s') s={i,j};
        if(c[i][j]=='g') g={i,j};
    }

    vector<vector<int>> cnt(H,vector<int>(W,INF));
    cnt[s.first][s.second]=0;
    queue<P> q;
    rep(n,3){
        rep(i,H) rep(j,W){
            if(cnt[i][j]==n) q.push({i,j});
        }
        while(!q.empty()){
            P p=q.front(); q.pop();
            rep(k,4){
                int i=p.first+I[k], j=p.second+J[k];
                if(0<=i && i<H && 0<=j && j<W){
                    if((c[i][j]=='.' || c[i][j]=='g') && cnt[i][j]==INF){
                        cnt[i][j]=n;
                        q.push({i,j});
                    }else if(c[i][j]=='#' && cnt[i][j]==INF){
                        cnt[i][j]=n+1;
                    }
                }
            }
        }
    }
    // rep(i,H){
    //     rep(j,W){
    //         if(cnt[i][j]!=INF) cout<<cnt[i][j]<<' ';
    //         else cout<<"# ";
    //     }
    //     cout<<endl;
    // }

    string ans="YES";
    if(cnt[g.first][g.second]>2) ans="NO";

    cout<<ans<<endl; 

    return 0;
}