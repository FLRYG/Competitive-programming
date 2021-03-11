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

ll N,K;

int main(){
    cin>>N>>K;
    vector<ll> cnt(N,0);
    rep(i,N){
        ll a;
        cin>>a;
        cnt[a]++;
    }
    rep(i,N) cnt[i]=min(K,cnt[i]);

    ll ans=0;
    rep(i,N){
        if(K==0) break;
        ans+=i*max(0LL,K-cnt[i]);
        K=min(K,cnt[i]);
    }
    ans+=K*(N-1);

    cout<<ans<<endl;
    
    return 0;
}