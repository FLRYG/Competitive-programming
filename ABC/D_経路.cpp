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
typedef pair<int,P> PP;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int H,W;
int a[1000][1000];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>a[i][j];

    vector<vector<int>> cnt(H,vector<int>(W,1));
    priority_queue<PP> q;
    rep(i,H){
        rep(j,W){
            q.push(PP(a[i][j],P(i,j)));
        }
    }

    while(!q.empty()){
        PP pp=q.top(); q.pop();
        int num=pp.first;
        int x=pp.second.first;
        int y=pp.second.second;
        rep(k,4){
            int i=x+I[k];
            int j=y+J[k];
            if(0<=i && i<H && 0<=j && j<W && a[i][j]<num){
                cnt[i][j]+=cnt[x][y];
                cnt[i][j]%=MOD;
            }
        }
    }

    int ans=0;
    rep(i,H){
        rep(j,W){
            ans+=cnt[i][j];
            ans%=MOD;
        }
    }

    cout<<ans<<endl;
}