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
ll x[100001];
ll v[100001];

int main(){
    cin>>N>>C;
    repn(i,N) cin>>x[i]>>v[i];

    repn(i,N) v[i]+=v[i-1];

    ll ans=0;
    repn(i,N) ans=max(ans,v[i]-x[i]);

    cout<<ans<<endl;
    
    return 0;
}