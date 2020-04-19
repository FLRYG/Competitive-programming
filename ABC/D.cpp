#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;
ll N,K;

int main(){
    cin>>N>>K;

    ll ans=0;
    for(ll i=K;i<=N+1;i++){
        ans+=N*(N+1)/2-(N-i)*(N-i+1)/2-i*(i-1)/2+1;
        ans%=MOD;
    }

    if(ans<0) ans+=MOD;
    cout<<ans<<endl;
}