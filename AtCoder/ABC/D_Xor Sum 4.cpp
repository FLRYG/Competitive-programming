#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;

ll N;
ll A[300000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    ll ans=0;
    for(int i=0;i<=60;i++){
        ll zero=0,one=0;
        rep(j,N){
            if(A[j]>>i&1) one++;
            else zero++;
        }
        ans+=(zero*one%MOD)*(((ll)1<<i)%MOD)%MOD;
        ans%=MOD;
    }
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
}