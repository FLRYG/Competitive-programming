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

int N,M,L;
int P,Q,R;

int main(){
    cin>>N>>M>>L>>P>>Q>>R;

    int ans=0;
    ans=max(ans,(N/P)*(M/Q)*(L/R));
    ans=max(ans,(N/P)*(M/R)*(L/Q));
    ans=max(ans,(N/Q)*(M/P)*(L/R));
    ans=max(ans,(N/Q)*(M/R)*(L/P));
    ans=max(ans,(N/R)*(M/P)*(L/Q));
    ans=max(ans,(N/R)*(M/Q)*(L/P));

    cout<<ans<<endl;
}