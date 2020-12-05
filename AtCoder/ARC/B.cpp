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

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1);
    return mpow(x*x,n/2);
}

char u[3]={'0','1','1'};

ll N;
string T;

int main(){
    cin>>N>>T;

    if(T=="1"){
        cout<<mpow(10,10)*2<<endl;
        return 0;
    }
    if(T=="11"){
        cout<<mpow(10,10)<<endl;
        return 0;
    }

    ll zero;
    rep(i,N){
        if(T[i]=='0'){
            zero=i;
            break;
        }
    }

    if(zero>2){
        cout<<0<<endl;
        return 0;
    }

    int idx;
    if(zero==0) idx=0;
    if(zero==1) idx=2;
    if(zero==2) idx=1;
    rep(i,N){
        if(T[i]!=u[(i+idx)%3]){
            cout<<0<<endl;
            return 0;
        }
    }

    ll ans=mpow(10,10)-1-(N-zero-1)/3;
    if(T[N-1]=='0') ans++;

    cout<<ans<<endl;
    
    return 0;
}