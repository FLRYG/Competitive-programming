#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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

ll N;
ll A[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    sort(A,A+N);

    vector<ll> sum(N+1);
    repn(i,N){
        sum[i]=sum[i-1]+A[i-1];
    }

    ll ans=0;
    repn(k,N){
        rep(i,N-k+1){
            ans+=sum[i+k]-sum[i];
        }
    }

    cout<<ans<<endl;
    
    return 0;
}