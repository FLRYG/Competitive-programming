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
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N,M;
int g[13][13];

int main(){
    cin>>N>>M;
    rep(i,M){
        int x,y;
        cin>>x>>y;
        g[x][y]=1;
        g[y][x]=1;
    }
    repn(i,N){
        g[i][i]=1;
    }

    int ans=0;
    rep(i,1<<N){
        int res=0;
        rep(j,N){
            int s=i>>j&1;
            //cout<<s;
            if(s==0) continue;
            res++;
            rep(k,N){
                int t=i>>k&1;
                if(t==0) continue;
                if(g[j+1][k+1]==0) goto a;
            }
        }
        //cout<<' '<<res<<endl;
        ans=max(ans,res);
        a:;
    }

    cout<<ans<<endl;
}