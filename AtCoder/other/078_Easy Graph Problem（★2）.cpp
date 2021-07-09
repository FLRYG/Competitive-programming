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

int N,M;

int main(){
    cin>>N>>M;
    vector<vector<int>> G(N);
    rep(i,M){
        int a,b;
        cin>>a>>b, a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    rep(i,N) sort(G[i].begin(),G[i].end());

    int ans=0;
    rep(i,N){
        if(G[i].size()==1 && G[i][0]<i){
            ans++;
        }else if(G[i].size()>1 && G[i][0]<i && i<G[i][1]){
            ans++;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}