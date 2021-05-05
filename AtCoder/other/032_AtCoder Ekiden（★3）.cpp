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
int A[10][10];
int ng[10][10];

int main(){
    cin>>N;
    rep(i,N) rep(j,N) cin>>A[i][j];
    cin>>M;
    rep(i,M){
        int x,y;
        cin>>x>>y;
        x--, y--;
        ng[x][y]=1;
        ng[y][x]=1;
    }

    vector<int> perm(N,0);
    iota(perm.begin(),perm.end(),0);
    int ans=INF;
    do{
        bool flag=false;
        rep(i,N-1){
            flag|=ng[perm[i]][perm[i+1]];
        }
        if(flag) continue;
        int res=0;
        rep(i,N) res+=A[perm[i]][i];
        ans=min(ans,res);
    }while(next_permutation(perm.begin(),perm.end()));
    if(ans==INF) ans=-1;

    cout<<ans<<endl;
    
    return 0;
}