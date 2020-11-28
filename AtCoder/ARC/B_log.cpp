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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll n;

int main(){
    cin>>n;

    ll l=0;
    ll r=2e9;
    while(r-l>1) {
        ll mid=(l+r)/2;
        if (mid*(mid+1)/2>n+1) r=mid;
        else l=mid;
    }
    ll ans=n-l+1;

    cout<<ans<<endl;
    
    return 0;
}