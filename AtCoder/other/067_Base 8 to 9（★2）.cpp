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

ll K;

string f(string x){
    ll res=0, y=1, n=x.size();
    rep(i,n){
        res+=(x[n-1-i]-'0')*y;
        y*=8;
    }
    string ans;
    while(res>0){
        ans+=(res%9)+'0';
        res/=9;
    }
    repr(e,ans) if(e=='8') e='5';
    reverse(ans.begin(),ans.end());
    if(ans.size()==0) return "0";
    return ans;
}

int main(){
    string ans;
    cin>>ans>>K;

    rep(i,K) ans=f(ans);

    cout<<ans<<endl;
    
    return 0;
}