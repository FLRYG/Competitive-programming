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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

ll N,A,B;
ll X[100000];

int main(){
    cin>>N>>A>>B;
    rep(i,N) cin>>X[i];

    ll ans=0;
    rep(i,N-1){
        ll walk=A*(X[i+1]-X[i]);
        ans+=min(walk,B);
    }

    cout<<ans<<endl;
}