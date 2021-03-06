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
typedef pair<int,P> IP;
typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int H,W,K;
int x1,y1,x2,y2;
vector<vector<char>> G;

int main(){
    cin>>H>>W>>K;
    cin>>x1>>y1>>x2>>y2;
    x1--, y1--;
    x2--, y2--;
    G.resize(H);
    rep(i,H) G[i].resize(W);
    rep(i,H) rep(j,W) cin>>G[i][j];

    vector<vector<int>> cnt(H,vector<int>(W,INF));
    priority_queue<PP> q;
    q.push(PP({x1,y1},{x1,x1}));

    
    return 0;
}