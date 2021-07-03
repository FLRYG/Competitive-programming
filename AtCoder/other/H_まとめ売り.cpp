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
#define rep(i,n) for(ll i=0;i<n;i++)
#define repn(i,n) for(ll i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<ll,ll> P;
// typedef pair<ll,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
ll const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N,Q;
ll C[200001];

int main(){
    cin>>N;
    repn(i,N) cin>>C[i];
    cin>>Q;

    ll minall=INF, minodd=INF, mineven=INF;
    repn(i,N){
        if(i&1) minodd=min(minodd,C[i]);
        else mineven=min(mineven,C[i]);
    }
    minall=min(minodd,mineven);

    ll ans=0;
    ll sum=0, odd=0;
    while(Q--){
        ll t,x,a;
        cin>>t;
        if(t==1){
            cin>>x>>a;
            if(x&1 && C[x]-sum-odd>=a){
                C[x]-=a;
                ans+=a;
                minodd=min(minodd,C[x]);
            }
            if(!(x&1) && C[x]-sum>=a){
                C[x]-=a;
                ans+=a;
                mineven=min(mineven,C[x]);
            }
            minall=min(minodd-odd,mineven);
        }else if(t==2){
            cin>>a;
            if(minodd-odd-sum>=a){
                odd+=a;
                ans+=a*((N+1)/2);
            }
            minall=min(minodd-odd,mineven);
        }else{
            cin>>a;
            if(minall-sum>=a){
                sum+=a;
                ans+=a*N;
            }
        }
        // cout<<minall<<endl;
        // repn(i,N){
        //     if(i&1) cout<<C[i]-odd-sum<<' ';
        //     else cout<<C[i]-sum<<' ';
        // } cout<<endl;
    }

    cout<<ans<<endl;
    
    return 0;
}