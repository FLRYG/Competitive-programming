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
ll const MOD=1000000007;

ll N;
ll A[100000];
ll B[100000];
ll cnt[100001];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i]>>B[i];

    for(int i=N-1;i>=0;i--){
        cnt[i]=cnt[i+1];
        cnt[i]+=(B[i]-(A[i]+cnt[i])%B[i])%B[i];
    }

    ll ans=cnt[0];
    cout<<ans<<endl;
}