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
// typedef pair<P,int> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N;
ll x[100000];
ll y[100000];
P xi[100000];
P yi[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i];
    rep(i,N){
        xi[i].first=x[i];
        yi[i].first=y[i];
        xi[i].second=yi[i].second=i;
    }

    sort(xi,xi+N);
    sort(yi,yi+N);

    vector<int> idx(1,0), idy(1,0);
    rep(i,N-1){
        if(xi[i].first!=xi[i+1].first) idx.push_back(i+1);
        if(yi[i].first!=yi[i+1].first) idy.push_back(i+1);
    }
    idx.push_back(N);
    idy.push_back(N);

    vector<vector<int>> G(N,vector<int>(0));
    rep(i,idx.size()-2){
        for(int j=idx[i];j<idx[i+1];j++){
            for(int k=idx[i+1];k<idx[i+2];k++){
                
            }
        }
    }
    
    return 0;
}