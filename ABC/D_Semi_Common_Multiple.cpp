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
using namespace std;
typedef long long ll;

template<class T>T gcd(T a, T b){if(a<b){a^=b;b^=a;a^=b;}return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

ll N,M;
ll a[100000];

int main(){
    cin>>N>>M;
    rep(i,N){
        cin>>a[i];
        a[i]/=2;
    }

    ll l=1;
    rep(i,N){
        l=lcm(l,a[i]);
        if(l>M){
            cout<<0<<endl;
            return 0;
        }
    }

    bool b=true;
    rep(i,N){
        b&=(l/a[i])&1;
    }
    if(!b){
        cout<<0<<endl;
        return 0;
    }

    ll ans=(M/l+1)/2;
    cout<<ans<<endl;
}