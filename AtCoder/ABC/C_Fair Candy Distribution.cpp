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
ll a[200000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>a[i];

    vector<ll> id(N);
    iota(id.begin(),id.end(),0);
    sort(id.begin(),id.end(),[&](ll i, ll j){ return a[i]<a[j]; });

    ll base=K/N;
    K%=N;
    vector<ll> plus(N,0);
    rep(i,K) plus[id[i]]++;

    rep(i,N){
        cout<<base+plus[i]<<endl;
    }
    
    return 0;
}