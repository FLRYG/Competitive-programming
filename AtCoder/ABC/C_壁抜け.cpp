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
typedef pair<ll,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int const I[]={1,0,-1,0};
int const J[]={0,1,0,-1};

int H,W,T;
char s[10][10];

int main(){
    cin>>H>>W>>T;
    rep(i,H) rep(j,W) cin>>s[i][j];
    int si, sj;
    rep(i,H) rep(j,W){
        if(s[i][j]=='S') si=i, sj=j;
    }

    ll ok=1, ng=INF;
    while(ng-ok>1){
        ll mid=(ok+ng)/2;
        // cout<<ok<<' '<<ng<<endl;
        vector<vector<ll>> cost(H,vector<ll>(W,LINF));
        priority_queue<IP,vector<IP>,greater<IP>> q;
        q.push(IP(0,{si,sj}));
        while(!q.empty()){
            IP p=q.top(); q.pop();
            ll v=p.first;
            int i=p.second.first, j=p.second.second;
            if(cost[i][j]<=v) continue;
            cost[i][j]=v;
            if(s[i][j]=='G'){
                if(v<=T) ok=mid;
                else ng=mid;
                // cout<<v<<endl;
                break;
            }
            rep(k,4){
                int x=i+I[k];
                int y=j+J[k];
                if(0<=x && x<H && 0<=y && y<W){
                    if(s[x][y]=='.' || s[x][y]=='G') q.push(IP(v+1,{x,y}));
                    else if(s[x][y]=='#') q.push(IP(v+mid,{x,y}));
                }
            }
        }
    }

    cout<<ok<<endl;
    
    return 0;
}