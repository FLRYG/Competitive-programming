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

ll mfrac(ll n){
    if(n==0) return 1;
    else return n*mfrac(n-1);
}

ll mperm(ll n,ll r){
    ll res=1;
    for(ll i=0;i<r;i++) res=res*(n-i);
    return res;
}

ll mcomb(ll n,ll r){
    if(r>n-r) r=n-r;
    ll res=mperm(n,r);
    return res*mpow(mfrac(r),MOD-2);
}

string S;
int N;

void input(){
    cin>>S;
    N=S.size();
}

void solve1(){
    ll ans=0;
    rep(i,1<<N-1){
        ll sum=0;
        ll x=S[0]-'0';
        rep(j,N-1){
            if(i>>j&1){
                sum+=x;
                //cout<<x<<' ';
                x=S[j+1]-'0';
            }else{
                int m=S[j+1]-'0';
                x=x*10+m;
            }
        }
        sum+=x;
        //cout<<x<<endl;
        ans+=sum;
    }

    cout<<ans<<endl;
}

void solve2(){
    ll ans=0;
    rep(i,N){
        ll x=0;
        for(int j=i;j<N;j++){
            x=x*10+S[j]-'0';
            ll m=N-1-(j-i)-2;
            if(i==0) m++;
            if(j==S.size()-1) m++;
            ans+=mpow(2,m)*x;
        }
    }
    cout<<ans<<endl;
}

int main(){
    input();

    //solve1();
    solve2();
}