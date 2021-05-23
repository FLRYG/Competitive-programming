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

int N,P;
string S;

int main(){
    cin>>N>>P>>S;

    vector<ll> cnt(P,0);
    cnt[0]++;
    int x=0, ten=1;
    rep(i,N){
        x+=ten*(S[N-1-i]-'0')%P;
        x%=P;
        cnt[x]++;
        ten*=10;
        ten%=P;
    }

    ll ans=0;
    rep(i,P){
        // cout<<i<<' '<<cnt[i]<<endl;
        ans+=cnt[i]*(cnt[i]-1)/2;
    }

    cout<<ans<<endl;
    
    return 0;
}