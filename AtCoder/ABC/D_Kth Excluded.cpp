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

    while(Q--){
        ll K;
        cin>>K;
        ll l=0, r=LINF;
        while(r-l>1){
            ll m=(l+r)/2;
            ll l2=0, r2=N+1;
            while(r2-l2>1){
                ll m2=(l2+r2)/2;
                if(A[m2]<=m) l2=m2;
                else r2=m2;
            }
            // cout<<"m,l2 "<<m<<' '<<l2<<endl;
            if(m-l2<K) l=m;
            else r=m;
        }
        cout<<r<<endl;
    }
    
    return 0;
}