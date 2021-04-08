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

ll mcomb(ll n,ll r){
    if(r>n-r) r=n-r;
    ll res=1;
    rep(i,r){
        res*=n-i;
        res/=i+1;
    }
    return res;
}

ll N,M;

int main(){
    cin>>N>>M;
    vector<vector<int>> G(N,vector<int>(0));
    rep(i,M){
        int x,y;
        cin>>x>>y;
        x--, y--;
        G[x].push_back(y);
    }

    vector<ll> dp(1<<N,0);
    dp[0]=1;
    repn(i,(1<<N)-1){
        ll res=0;
        rep(j,N){
            if(i>>j&1){
                int cnt=0;
                repr(e,G[j]) cnt+=i>>e&1;
                if(cnt==0) res+=dp[i^1<<j];
            }   
        }
        dp[i]=res;
    }

    cout<<dp[(1<<N)-1]<<endl;
    
    return 0;
}