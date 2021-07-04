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

ll N,W,C;
ll L[100000];
ll R[100000];
ll P[100000];

int main(){
    cin>>N>>W>>C;
    rep(i,N) cin>>L[i]>>R[i]>>P[i];

    // vector<ll> v(2*N);
    // rep(i,N) v[2*i]=L[i]-C+1, v[2*i+1]=R[i];
    // sort(v.begin(),v.end());

    // unordered_map<ll,ll> id;
    // rep(i,2*N) id[v[i]]=i+1;
    unordered_map<ll,ll> id;
    rep(i,N) id[L[i]-C+1], id[R[i]];
    id[0];
    int k=0;
    repr(e,id) e.second=++k;

    rep(i,2*N) id[v[i]]=i+1;

    vector<ll> cost(id.size()+2,0);
    rep(i,N){
        cost[id[L[i]]]+=P[i];
        cost[id[R[i]]+1]-=P[i];
    }
    
    return 0;
}