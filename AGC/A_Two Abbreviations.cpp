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

template<class T>T gcd(T a, T b){if(a<b){a^=b;b^=a;a^=b;}return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

ll N,M;
string S,T;

int main(){
    cin>>N>>M>>S>>T;

    ll g=gcd(N,M);
    ll n=min(N,M);
    ll m=max(N,M);
    string s=N<M?S:T;
    string t=N<M?T:S;
    rep(i,g){
        if(s[i*(n/g)]!=t[i*(m/g)]){
            cout<<-1<<endl;
            return 0;
        }
    }

    ll ans=n/g*m;
    cout<<ans<<endl;
}