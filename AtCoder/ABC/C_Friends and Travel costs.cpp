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
typedef pair<ll,ll> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
P A[200000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i].first>>A[i].second;

    sort(A,A+N);

    ll pos=0;
    rep(i,N){
        if(A[i].first-pos>K) break;
        K-=A[i].first-pos;
        pos=A[i].first;
        K+=A[i].second;
    }
    if(K>0) pos+=K;

    cout<<pos<<endl;
    
    return 0;
}