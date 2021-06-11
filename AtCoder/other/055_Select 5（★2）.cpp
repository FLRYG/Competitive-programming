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

ll N,P,Q;
ll A[100];

int main(){
    cin>>N>>P>>Q;
    rep(i,N) cin>>A[i];

    ll ans=0;
    for(int i=0;i<N-4;i++)
    for(int j=i+1;j<N-3;j++)
    for(int k=j+1;k<N-2;k++)
    for(int l=k+1;l<N-1;l++)
    for(int m=l+1;m<N;m++){
        if(A[i]*A[j]%P*A[k]%P*A[l]%P*A[m]%P==Q) ans++;
    }

    cout<<ans<<endl;
    
    return 0;
}