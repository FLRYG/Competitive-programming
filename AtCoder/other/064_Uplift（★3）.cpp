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

ll N,Q;
ll A[100001];

int main(){
    cin>>N>>Q;
    repn(i,N) cin>>A[i];

    ll ans=0;
    vector<ll> diff(N+2,0);
    repn(i,N-1){
        diff[i]=A[i+1]-A[i];
        ans+=abs(A[i+1]-A[i]);
    }

    while(Q--){
        ll L,R,V;
        cin>>L>>R>>V;
        if(L!=1){
            ans-=abs(diff[L-1]);
            diff[L-1]+=V;
            ans+=abs(diff[L-1]);
        }
        if(R!=N){
            ans-=abs(diff[R]);
            diff[R]-=V;
            ans+=abs(diff[R]);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}