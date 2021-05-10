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
typedef pair<int,int> Pa;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M,P,Q,R;

int main(){
    cin>>N>>M>>P>>Q>>R;
    vector<vector<Pa>> val(N,vector<Pa>(0));
    rep(i,R){
        int x,y,z;
        cin>>x>>y>>z;
        x--, y--;
        val[x].push_back({y,z});
    }

    int ans=0;
    rep(i,1<<N){
        int cnt=0;
        rep(j,N) cnt+=i>>j&1;
        if(cnt!=P) continue;
        vector<int> scr(M,0);
        rep(j,N) if(i>>j&1){
            repr(e,val[j]) scr[e.first]+=e.second;
        }
        sort(scr.begin(),scr.end(),greater<int>());
        int sum=0;
        rep(i,Q) sum+=scr[i];
        ans=max(ans,sum);        
    }

    cout<<ans<<endl;
    
    return 0;
}