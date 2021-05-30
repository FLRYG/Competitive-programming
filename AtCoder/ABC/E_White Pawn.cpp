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
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M;
P X[200000];

void f(int x, int y, map<int,int> &cnt, map<int,vector<int>> &m, map<P,int> &chk){
    if(x==2*N+1) return;
    if(*(m[y].end()-2)==x) cnt[y]=1;
    if(chk[{x,y}]) return;
    chk[{x,y}]=1;
    vector<int> &vec=m[y];
    int nextx=*(lower_bound(vec.begin(),vec.end(),x)+1);
    if(y>0){
        vector<int> &v=m[y-1];
        repr(e,v) if(x<e && e<=nextx) f(e,y-1,cnt,m,chk);
    }
    if(y<2*N){
        vector<int> &v=m[y+1];
        repr(e,v) if(x<e && e<=nextx) f(e,y+1,cnt,m,chk);
    }
}

int main(){
    cin>>N>>M;
    map<int,vector<int>> m;
    m[N].push_back(0);
    rep(i,M){
        int x,y;
        cin>>x>>y;
        m[y].push_back(x);
    }
    repr(e,m) e.second.push_back(2*N+1);
    repr(e,m) sort(e.second.begin(),e.second.end());

    map<int,int> cnt;
    map<P,int> chk;

    f(0,N,cnt,m,chk);

    cout<<cnt.size()<<endl;
    
    return 0;
}