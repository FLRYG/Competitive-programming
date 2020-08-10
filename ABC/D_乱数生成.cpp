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
//typedef pair<ll,ll> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

double N,K;

int main(){
    cin>>N>>K;

    double ans=0;
    ans+=((K-1)/N)*(1/N)*((N-K)/N)*6;
    ans+=(1/N)*(1/N)*((N-1)/N)*3;
    ans+=(1/N)*(1/N)*(1/N);

    cout<<setprecision(16)<<ans<<endl;
}