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

int main(){
    cin>>N;

    ll cnt=0;
    for(ll n=N;n>0;n>>=1) cnt++;

    bool flag;
    if(cnt&1){
        flag=false;
        rep(i,cnt-1){
            cout<<(i&1)<<' '<<(~(N>>i&1))<<endl;
            if(i&1 && !(N>>i&1)) flag=true;
        }
    }else{
        flag=true;
        rep(i,cnt-1){
            if(!(i&1) && !(N>>i&1)) flag=false;
        }
    }

    string ans="Aoki";
    if(flag) ans="Takahashi";

    cout<<ans<<endl;

    return 0;
}