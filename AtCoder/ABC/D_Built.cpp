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

ll N;
P xy[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>xy[i].first>>xy[i].second;

    sort(xy,xy+N);

    ll prevx=xy[0].first;
    bool flag=true;
    set<ll> s;
    ll ans=0;
    rep(i,N){
        if(xy[i].first==prevx){
            if(s.find(xy[i].second)!=s.end()) flag=false;
            s.insert(xy[i].second);
        }else{
            if(flag) ans+=
        }
    }
    
    return 0;
}