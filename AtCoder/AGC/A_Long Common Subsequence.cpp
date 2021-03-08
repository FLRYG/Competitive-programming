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

string mpow(string x,ll n){
    if(n==0) return "";
    else if(n%2) return x+mpow(x,n-1);
    return mpow(x+x,n/2);
}

int T;

int main(){
    cin>>T;

    vector<string> ans(T,"");
    rep(t,T){
        int N;
        string S[3];
        cin>>N;
        rep(i,3) cin>>S[i];
        string zer=mpow("0",N);
        ans[t]+=zer;
        ans[t]+='1';
        ans[t]+=zer;
    }

    repr(e,ans) cout<<e<<endl;
    
    return 0;
}