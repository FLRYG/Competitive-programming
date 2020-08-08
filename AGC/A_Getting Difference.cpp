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
ll const MOD=1000000007;

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

int N,K;
int A[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    int maxi=0;
    rep(i,N) maxi=max(maxi,A[i]);
    
    int g=0;
    rep(i,N) g=gcd(g,A[i]);

    string ans;
    if(maxi<K || K%g!=0) ans="IMPOSSIBLE";
    else ans="POSSIBLE";

    cout<<ans<<endl;
}