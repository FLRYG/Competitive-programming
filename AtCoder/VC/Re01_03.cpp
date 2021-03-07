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
ll const MOD=2019;

int mpow(int x, int n){
    if(n==0) return 1;
    if(n&1) return x*mpow(x,n-1)%MOD;
    return mpow(x*x%MOD,n/2)%MOD;
}

string S;

int main(){
    cin>>S;
    int N=S.size();

    vector<int> cnt(2019,0);
    cnt[0]=1;
    int x=0;
    ll ans=0;
    for(int i=N-1;i>=0;i--){
        x+=(S[i]-'0')*mpow(10,N-1-i);
        x%=MOD;
        ans+=cnt[x];
        cnt[x]++;
    }

    cout<<ans<<endl;
    
    return 0;
}