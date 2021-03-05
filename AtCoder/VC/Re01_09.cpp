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

int popcount(int n){
    int res=0;
    while(n>0){
        res+=n&1;
        n>>=1;
    }
    return res;
}

int f(int n){
    if(n==0) return 0;
    return 1+f(n%popcount(n));
}

ll mpow(ll x,ll n,ll MOD){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1,MOD)%MOD;
    return mpow(x*x%MOD,n/2,MOD)%MOD;
}

int N;
string X;

int main(){
    cin>>N>>X;

    int cnt=0;
    rep(i,N) cnt+=X[i]&1;

    int x=0, y=0;
    rep(i,N){
        x=x*2+(X[i]-'0');
        y=y*2+(X[i]-'0');
        x%=cnt+1;
        if(cnt>1) y%=cnt-1;
    }
    rep(i,N){
        int z;
        if(X[i]=='1'){
            if(cnt==1){
                cout<<0<<endl;
                continue;
            }
            z=y-mpow(2,N-1-i,cnt-1);
            z%=cnt-1;
            if(z<0) z+=cnt-1;
        }else{
            z=x+mpow(2,N-1-i,cnt+1);
            z%=cnt+1;
            if(z<0) z+=cnt+1;
        }
        cout<<1+f(z)<<endl;
    }
    
    return 0;
}