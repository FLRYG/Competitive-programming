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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
ll s[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>s[i];

    rep(i,N) if(!s[i]){
        cout<<N<<endl;
        return 0;
    }

    ll ans=0;
    ll j=0;
    ll x=1;
    rep(i,N){
        j=max(i,j);
        while(s[j]<=K/x && j<N) x*=s[j++];
        // cout<<i<<' '<<j<<' '<<x<<endl;
        ans=max(ans,j-i);
        if(i<j) x/=s[i];
    }

    cout<<ans<<endl;
    
    return 0;
}