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
string S;

int main(){
    cin>>N>>S;

    ll ans=0, a=0, b=0, r=0;
    rep(l,N){
        while(r<N && (a==0 || b==0)){
            if(S[r]=='o') a++;
            else b++;
            r++;
        }
        // cout<<l<<' '<<r<<endl;
        if(a>0 && b>0) ans+=N-r+1;
        if(S[l]=='o') a--;
        else b--;
    }

    cout<<ans<<endl;
    
    return 0;
}