#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,D;
ll X[200000];
ll Y[200000];

int main(){
    cin>>N>>D;
    rep(i,N) cin>>X[i]>>Y[i];

    D*=D;
    rep(i,N) X[i]*=X[i];
    rep(i,N) Y[i]*=Y[i];

    ll ans=0;
    rep(i,N) if(X[i]+Y[i]<=D) ans++;

    cout<<ans<<endl;
}