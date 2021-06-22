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

int N;

int main(){
    cin>>N;
    vector<ll> A(N+2), B(N+1);
    repn(i,N+1) cin>>A[i];
    repn(i,N) cin>>B[i];

    vector<ll> id(N+2);
    iota(id.begin(),id.end(),0);
    sort(id.begin(),id.end(),[&](int a, int b){ return A[a]<A[b]; });
    sort(B.begin(),B.end());

    vector<ll> diff1(N+2), diff2(N+2);
    repn(i,N) diff1[i]=max(diff1[i-1],max(A[id[i]]-B[i],0LL));
    repn(i,N) diff2[N+1-i]=max(diff2[N+2-i],max(A[id[N+2-i]]-B[N+1-i],0LL));
    
    // repr(e,diff1) cout<<e<<' '; cout<<endl;
    // repr(e,diff2) cout<<e<<' '; cout<<endl;

    vector<ll> ans(N+2);
    repn(i,N+1){
        ll c=max(diff1[i-1],diff2[i]);
        ans[id[i]]=c;
    }

    repn(i,N+1) cout<<ans[i]<<' '; cout<<endl;

    return 0;
}