#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N;
ll T[100000];
ll A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>T[i];
    rep(i,N) cin>>A[i];

    if(T[N-1]!=A[0]){
        cout<<0<<endl;
        return 0;
    }

    ll l=N-1, r=0;
    rep(i,N) if(T[i]==A[i] && T[i]!=A[0]){
        cout<<0<<endl;
        return 0;
    }
    rep(i,N) if(T[N-1-i]==A[N-1-i]) l=N-1-i;
    rep(i,N) if(T[i]==A[i]) r=i;

    if(l>r){
        cout<<0<<endl;
        return 0;
    }

    ll ans=1;
    repn(i,l){
        if(T[i-1]==T[i]){
            ans*=T[i];
            ans%=MOD;
        }
    }
    for(int i=N-2;i>=r;i--){
        if(A[i]==A[i+1]){
            ans*=A[i];
            ans%=MOD;
        }
    }

    if(r-l-1>0){
        rep(i,r-l-1){
            ans*=T[l];
            ans%=MOD;
        }
    }

    cout<<ans<<endl;

    return 0;
}