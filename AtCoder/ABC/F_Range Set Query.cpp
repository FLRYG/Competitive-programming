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

int N,Q;
int c[500000];

int main(){
    cin>>N>>Q;
    rep(i,N) cin>>c[i];

    vector<int> cnt(N+1,0), a(N+1,0);
    rep(i,N){
        a[i+1]=a[i];
        if(cnt[c[i]]==0) cnt[c[i]]=1;
        else a[i+1]++;
    }
    rep(i,N+1) cout<<a[i]<<' '; cout<<endl;

    vector<int> ans(0);
    ans.reserve(Q);
    while(Q--){
        int l,r;
        cin>>l>>r;
        ans.push_back(r-l+1-(a[r]-a[l-1]));
    }

    repr(e,ans) cout<<e<<endl;
}