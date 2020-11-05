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
typedef pair<ll,ll> P;

ll N;
ll A[100001];
ll sum[100001];

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];

    sort(A+1,A+N+1);

    repn(i,N) sum[i]=sum[i-1]+A[i];

    ll ans=1;
    repn(i,N-1){
        if(A[N-i+1]<=2*sum[N-i]) ans++;
        else break;
    }

    cout<<ans<<endl;
}