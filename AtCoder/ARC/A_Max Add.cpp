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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N;
ll A[200001];

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];

    vector<ll> maxi(N+1,0);
    vector<ll> sum(N+1,0);
    repn(i,N){
        maxi[i]=max(maxi[i-1],A[i]);
        sum[i]=sum[i-1]+A[i];
    }

    ll s=0;
    repn(i,N){
        s+=sum[i];
        ll ans=s+maxi[i]*i;
        cout<<ans<<endl;
    }
    
    return 0;
}