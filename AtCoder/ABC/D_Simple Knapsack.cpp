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
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,W;
int w[101];
int v[101];

int main(){
    cin>>N>>W;
    repn(i,N) cin>>w[i]>>v[i];

    map<int,int> w2id;
    w2id[0]=0;
    repn(i,N) rep(j,4) w2id[i*w[1]+j];
    int i=0;
    repr(e,w2id) e.second=i++; 

    vector<int> id2w(1,0);
    repr(e,w2id) id2w.push_back(e.first);

    vector<vector<int>> dp(N+1,vector<int>(id2w.size(),0));
    repn(i,N){
        repn(j,id2w.size()){
            dp[i][j]=dp[i-1][j];
            if(id2w[j]-w[i]>=0){
                rep(k,w2id[id2w[j]-w[i]]+1){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+v[i]);
                }
            }
        }
    }

    int ans=0;
    rep(i,w2id[W]+1) ans=max(ans,dp[N][i]);

    cout<<ans<<endl;
    
    return 0;
}