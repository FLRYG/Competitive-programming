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
// typedef pair<int,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,K;
ll A[200000];
ll F[200000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>F[i];
    sort(A,A+N);
    sort(F,F+N,greater<ll>());
    
    rep(i,N){
        if(K>=A[i]){
            K-=A[i];
            A[i]=0;
        }else{
            A[i]-=K;
            break;
        }
    }

    ll ans=0;
    rep(i,N){
        ans+=A[i]*F[i];
    }

    cout<<ans<<endl;
    
    return 0;
}