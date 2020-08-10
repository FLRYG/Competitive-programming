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

int N;
int R[3000];

int main(){
    cin>>N;
    rep(i,N) cin>>R[i];

    int ans=N;
    repn(i,N-2){
        if((R[i-1]>=R[i] || R[i]<=R[i+1]) && (R[i-1]<=R[i] || R[i]>=R[i+1])){
            ans--;
        }
    }
    if(ans<3) ans=0;

    cout<<ans<<endl;
}