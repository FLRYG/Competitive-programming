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
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll N;
map<ll,int> flag;
map<ll,int> memo;

int f(ll x, int p){
    if(2*x>N) return p;
    if(flag[x]) return memo[x];
    flag[x]=1;
    if(p){
        return memo[x]=!(f(2*x,0)|f(2*x+1,0));
    }else{
        return memo[x]=!(f(2*x,1)&f(2*x+1,1));
    }
}

int main(){
    cin>>N;

    string ans="Aoki";
    if(f(1,0)) ans="Takahashi";

    int 
    
    cout<<ans<<endl;

    return 0;
}