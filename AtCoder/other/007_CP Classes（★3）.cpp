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
ll A[300002];

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];
    A[0]=-LINF;
    A[N+1]=LINF;

    sort(A+1,A+N+1);

    cin>>Q;
    while(Q--){
        ll B;
        cin>>B;
        ll l=0, r=N+1;
        while(r-l>1){
            ll m=(l+r)/2;
            if(B<A[m]) r=m;
            else l=m;
        }
        ll ans=min(abs(A[l]-B),abs(A[r]-B));
        cout<<ans<<endl;
    }
    
    return 0;
}