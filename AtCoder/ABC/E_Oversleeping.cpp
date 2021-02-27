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

template<class T>T gcd(T a, T b){return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

int T;

int main(){
    cin>>T;

    rep(t,T){
        ll X,Y,P,Q;
        cin>>X>>Y>>P>>Q;
        ll ans;
        if(gcd(X+Y,P+Q)!=1){
            ll l=lcm(X+Y,P+Q);
            if(l-Y<=P && P<l);
        }else{
            if(P%(X+Y)>=X){
                ans=X;
            }else{
                ll diff=(P+Q)%(X+Y)-2*(P+Q)%(X+Y);
                
            }
        }
    }
    
    return 0;
}