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
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

ll N;
ll T[100];

int main(){
    cin>>N;
    rep(i,N) cin>>T[i];

    ll ans;
    rep(i,N){
        if(i==0){
            ans=T[i];
        }else{
            ans=lcm(ans,T[i]);
        }
    }

    cout<<ans<<endl;
}