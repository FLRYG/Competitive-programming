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
int c[30000];

int main(){
    cin>>N;
    rep(i,N) cin>>c[i];

    vector<int> dp(N,INF);
    rep(i,N){
        int ng=-1, ok=N;
        while(ok-ng>1){
            int m=(ng+ok)/2;
            if(c[i]<dp[m]) ok=m;
            else ng=m;
        }
        dp[ok]=c[i];
    }

    int ans=N;
    rep(i,N){
        if(dp[i]==INF) break;
        ans--;
    }

    cout<<ans<<endl;
    
    return 0;
}