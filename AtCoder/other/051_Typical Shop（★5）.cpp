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

ll N,K,P;
ll A[40];

int main(){
    cin>>N>>K>>P;
    rep(i,N) cin>>A[i];

    vector<vector<ll>> val1(K+1,vector<ll>(0));
    rep(i,1<<(N/2)){
        ll cost=0, cnt=0;
        rep(j,N/2) if(i>>j&1){
            cost+=A[j];
            cnt++;
        }
        if(cnt<=K) val1[cnt].push_back(cost);
    }
    repn(i,K) sort(val1[i].begin(),val1[i].end());

    vector<vector<ll>> val2(K+1,vector<ll>(0));
    rep(i,1<<((N+1)/2)){
        ll cost=0, cnt=0;
        rep(j,(N+1)/2) if(i>>j&1){
            cost+=A[N/2+j];
            cnt++;
        }
        if(cnt<=K) val2[cnt].push_back(cost);
    }
    repn(i,K) sort(val2[i].begin(),val2[i].end());

    ll ans=0;
    rep(i,K+1){
        int j=K-i;
        int r=val2[j].size()-1;
        rep(l,val1[i].size()){
            while(r>=0 && val1[i][l]+val2[j][r]>P) r--;
            ans+=r+1;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}