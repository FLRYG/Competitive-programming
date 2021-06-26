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
ll A[3001];

ll memo[3001][3001];

ll f(ll s, ll k){
    if(s==N+1) return 1;
    if(memo[s][k]!=-1) return memo[s][k];
    ll res=0, sum=0;
    for(int i=s;i<=N;i++){
        sum+=A[i];
        if(sum%k==0){
            res+=f(i+1,k+1);
            res%=MOD;
        }
    }
    return memo[s][k]=res; 
}

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];
    repn(i,N) repn(j,N) memo[i][j]=-1;

    ll ans=f(1,1)%MOD;

    cout<<ans<<endl;
    
    return 0;
}