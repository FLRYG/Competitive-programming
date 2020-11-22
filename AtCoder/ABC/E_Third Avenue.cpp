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

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int H,W;
char a[2000][2000];
int t[2000][2000];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>a[i][j];

    rep(i,H) rep(j,W) t[i][j]=-1;

    P G;
    queue<P> q;
    vector<vector<P>> v(26,vector<P>());
    rep(i,H) rep(j,W){
        if('a'<=a[i][j] && a[i][j]<='z'){
            v[a[i][j]-'a'].push_back(P(i,j));
        }
        if(a[i][j]=='S'){
            t[i][j]=0;
            q.push(P(i,j));
        }
        if(a[i][j]=='G'){
            G=P(i,j);
        }
    }

    vector<bool> chk(26,true);
    while(!q.empty()){
        P p=q.front(); q.pop();
        int i=p.first;
        int j=p.second;
        if('a'<=a[i][j] && a[i][j]<='z' && chk[a[i][j]-'a']){
            repr(e,v[a[i][j]-'a']){
                if(t[e.first][e.second]==-1){
                    t[e.first][e.second]=t[i][j]+1;
                    q.push(e);
                }
            }
            chk[a[i][j]-'a']=false;
        }
        rep(k,4){
            int x=i+I[k];
            int y=j+J[k];
            if(0<=x && x<H && 0<=y && y<W && a[x][y]!='#' && t[x][y]==-1){
                t[x][y]=t[i][j]+1;
                q.push(P(x,y));
            } 
        }
    }

    //rep(i,H){rep(j,W){cout<<t[i][j]<<' ';}cout<<endl;}

    int ans=t[G.first][G.second];

    cout<<ans<<endl;
    
    return 0;
}