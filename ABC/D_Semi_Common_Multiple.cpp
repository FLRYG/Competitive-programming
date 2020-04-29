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
map<ll,ll> m;

int main(){
    cin>>N>>M;
    rep(i,N){
        cin>>a[i];
        a[i]/=2;
        m[a[i]]++;
    }

    ll two=1;
    ll x=a[0];
    while(x%2==0){
        two*=2;
        x/=2;
    }
    repn(i,N-1){
        ll x=a[i];
        if(x%two!=0){
            cout<<0<<endl;
            return 0;
        }
        x/=two;
        if(x%2==0){
            cout<<0<<endl;
            return 0;
        }
    }

    ll l=a[0];
    m[0]=-1;
    repn(i,N-1){
        if(a[i]>0){
            l=lcm(l,a[i]);
            m[a[i]]=-1;
        }
    }

    int ans=M/l;
    ans=ans&1?ans/2+1:ans/2;
    cout<<ans<<endl;
}