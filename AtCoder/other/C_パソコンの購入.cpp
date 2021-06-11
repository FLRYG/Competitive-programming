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

ll D;
ll a[200000];
ll b[200000];

int main(){
    cin>>D;
    rep(i,D) cin>>a[i];
    rep(i,D) cin>>b[i];

    ll ans=LINF, sum=0;
    rep(i,D){
        sum+=a[i];
        if(b[i]<=sum) ans=min(ans,b[i]);
    }
    if(ans==LINF) ans=-1;

    cout<<ans<<endl;
    
    return 0;
}