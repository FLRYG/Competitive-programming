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

int N,K;

int main(){
    cin>>N>>K;
    vector<vector<int>> cnt(5001,vector<int>(5001,0));
    rep(i,N){
        int a,b;
        cin>>a>>b;
        cnt[a][b]++;
    }
    repn(i,5000) repn(j,5000){
        cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
    }

    int ans=0;
    repn(i,5000-K) repn(j,5000-K){
        ans=max(ans,cnt[i+K][j+K]-cnt[i-1][j+K]-cnt[i+K][j-1]+cnt[i-1][j-1]);
    }

    cout<<ans<<endl;
    
    return 0;
}