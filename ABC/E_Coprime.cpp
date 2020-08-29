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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

ll N;
ll A[1000000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    ll maxi=0;
    rep(i,N) maxi=max(maxi,A[i]);

    vector<ll> D(maxi+1,0);
    for(int i=2;i<=maxi;i++){
        for(int j=1;i*j<=maxi;j++){
            D[i*j]=j;
        }
    }

    vector<ll> cnt(1001);
    rep(i,N){
        ll a=A[i];
        while(a>1){
            ll m=D[a];
            while(a%m==0) a/=m;
            cnt[m]++;
        }
    }
    bool flag=true;
    rep(i,1000){
        if(cnt[i]>1) flag=false;
    }
    if(flag){
        cout<<"pairwise coprime"<<endl;
        return 0;
    }

    ll g=0;
    rep(i,N){
        g=gcd(g,A[i]);
    }
    if(g==1){
        cout<<"setwise coprime"<<endl;
    }else{
        cout<<"not coprime"<<endl;
    }
}


/*
ll N;
ll A[1000000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    ll l=A[0];
    ll cnt=0;
    bool flag=true;
    repn(i,N-1){
        ll X=((MOD%A[i])*(cnt%A[i])%A[i]+l)%A[i];
        if(gcd(A[i],X)!=1){
            flag=false;
            break;
        }
        l*=A[i];
        cnt+=l/MOD;
        l%=MOD;
    }
    if(flag){
        cout<<"pairwise coprime"<<endl;
        return 0;
    }

    ll g=0;
    rep(i,N){
        g=gcd(g,A[i]);
    }
    if(g==1){
        cout<<"setwise coprime"<<endl;
    }else{
        cout<<"not coprime"<<endl;
    }
}
*/