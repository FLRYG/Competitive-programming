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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,a,b,M;
vector<int> xy[100];
int dp[100][100];

int main(){
    cin>>N>>a>>b>>M;
    a--, b--;
    rep(i,M){
        int u,v;
        cin>>u>>v;
        xy[u-1].push_back(v-1);
        xy[v-1].push_back(u-1);
    }

    rep(i,N) fill(dp[i],dp[i]+N,INF);
    rep(i,N) dp[i][i]=0;
    rep(i,N){
        repr(j,xy[i]){
            dp[i][j]=1;
            dp[j][i]=1;
        }
    }

    rep(k,N){
        rep(i,N){
            rep(j,N){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

    vector<ll> cnt(N,0);
    vector<bool> chk(N,false);
    cnt[a]=1;
    queue<int> q;
    q.push(a);
    q.push(-1);
    int step=0;
    while(step<dp[a][b]){
        int p=q.front(); q.pop();
        if(p==-1){
            step++;
            //cout<<"step++\n"<<endl;
            q.push(-1);
            continue;
        }
        repr(e,xy[p]){
            if(dp[e][b]<dp[p][b]){
                cnt[e]+=cnt[p];
                cnt[p]%=MOD;
                if(!chk[e]){
                    q.push(e);
                    chk[e]=true;
                }
            }
        }
        //rep(i,N) cout<<i+1<<':'<<cnt[i]<<endl;
        //cout<<endl;
    }
    cnt[b]%=MOD;

    cout<<cnt[b]<<endl;
}