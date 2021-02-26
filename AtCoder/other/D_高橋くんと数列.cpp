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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,C;
ll a[100000];

int main(){
    cin>>N>>C;
    rep(i,N) cin>>a[i];

    vector<vector<ll>> idx(C,vector<ll>(1,-1));
    rep(i,N) idx[a[i]-1].push_back(i);

    vector<ll> ans(C);
    rep(c,C){
        repn(i,idx[c].size()-1){
            ans[c]+=(idx[c][i]-idx[c][i-1])*(N-idx[c][i]);
        }
    }

    rep(i,C) cout<<ans[i]<<endl;
    
    return 0;
}