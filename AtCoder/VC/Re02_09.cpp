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
ll A[300][300];

int main(){
    cin>>N;
    rep(i,N) rep(j,N) cin>>A[i][j];

    ll ans=0;
    rep(i,N) rep(j,N){
        bool flag=true;
        rep(k,N){
            if(k==i || k==j) continue;
            if(A[i][k]+A[k][j]<A[i][j]){
                cout<<-1<<endl;
                return 0;
            }else if(A[i][k]+A[k][j]==A[i][j]){
                flag=false;
            }
        }
        if(flag) ans+=A[i][j];
    }
    ans/=2;

    cout<<ans<<endl;
    
    return 0;
}