#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

template<class T>T gcd(T a, T b){if(a<b){a^=b;b^=a;a^=b;}return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a*b/gcd(a,b);}

ll A,B;

int main(){
    cin>>A>>B;

    ll g=gcd(A,B);
    ll sg=sqrt(g);
    ll div=1;
    ll ans=1;
    bool b;
    while(div<sg){
        div++;
        if(g%div==0){
            ans++;
            while(g%div==0) g/=div;
        }
    }
    if(g!=1) ans++;

    cout<<ans<<endl;
}