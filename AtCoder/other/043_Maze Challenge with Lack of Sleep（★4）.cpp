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
typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int const I[]={1,0,-1,0};
int const J[]={0,1,0,-1};

int H,W,rs,cs,rt,ct;
string S[1000];

int main(){
    cin>>H>>W>>rs>>cs>>rt>>ct;
    rep(i,H) cin>>S[i];

    vector<vector<int>> cost(H,vector<int>(W,INF));
    priority_queue<IP,vector<IP>,greater<IP>> q;
    cost[rs][cs]=0;
    rep(k,4){
        int i=rs+I[k];
        int j=cs+J[k];
        if(0<=i && i<H && 0<=j && j<W && S[i][j]=='.'){
            q.push({0,{i,j}});
        }
    }
    while(!q.empty()){
        IP ip=q.top(); q.pop();
        int v=ip.first;
        int i=ip.second.first;
        int j=ip.second.second;
        if(v>=cost[i][j]) continue;
        cost[i][j]=v;
        if(i==rt && j==ct) break;
        cout<<i<<' '<<j<<endl;
        rep(k,4){
            int x=i+I[k];
            int y=j+J[k];
            int c=INF+3;
            if(0<=x && x<H && 0<=y && y<W && S[x][y]=='.'){
                rep(l,4){
                    int z=i+I[l];
                    int w=j+J[l];
                    if(0<=z && z<H && 0<=w && w<W && k!=l){
                        if((k&1)^(l&1)) c=min(c,cost[z][w]+1);
                        else c=min(c,cost[i][j]);
                    }
                }
                q.push({c,{x,y}});
            }
        }
    }

    cout<<cost[rt][ct]<<endl;

    return 0;
}