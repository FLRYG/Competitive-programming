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

int N;

int main(){
    cin>>N;
    vector<vector<int>> G(1002,vector<int>(1002,0));
    rep(i,N){
        int lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;
        lx++, ly++, rx++, ry++;
        G[lx][ly]++;
        G[lx][ry]--;
        G[rx][ly]--;
        G[rx][ry]++;
    }

    vector<int> ans(N+1,0);
    repn(i,1000){
        repn(j,1000){
            G[i][j]+=G[i-1][j]+G[i][j-1]-G[i-1][j-1];
            ans[G[i][j]]++;
        }
    }

    repn(i,N) cout<<ans[i]<<endl;
    
    return 0;
}