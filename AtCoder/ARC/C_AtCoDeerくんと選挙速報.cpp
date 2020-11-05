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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N;
ll T[1000];
ll A[1000];

int main(){
    cin>>N;
    rep(i,N) cin>>T[i]>>A[i];

    repn(i,N-1){
        ll m=max((T[i-1]-1)/T[i],(A[i-1]-1)/A[i])+1;
        T[i]*=m;
        A[i]*=m;
    }

    ll ans=T[N-1]+A[N-1];
    cout<<ans<<endl;
}