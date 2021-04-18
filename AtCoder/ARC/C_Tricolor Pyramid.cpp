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
ll const MOD=3;

ll N;
ll x[400000];

int main(){
    cin>>N;
    rep(i,N){
        char c;
        cin>>c;
        if(c=='B') x[i]=0;
        if(c=='W') x[i]=1;
        if(c=='R') x[i]=2;
    }

    ll sum=0;
    ll a=1, b=1;
    ll cnt=0;
    rep(i,N){
        if(cnt==0) sum+=a*b*x[i]%3;
        if(i==N-1) break;
        ll m=N-1-i;
        while(m%3==0){
            m/=3;
            cnt++;
        }
        a*=m;
        a%=3;
        ll k=i+1;
        while(k%3==0){
            k/=3;
            cnt--;
        }
        b*=k;
        b%=3;
    }
    sum%=3;
    if(!(N&1)) sum*=-1;
    // cout<<sum<<endl;
    if(sum<0) sum+=3;

    char ans;
    if(sum==0) ans='B';
    if(sum==1) ans='W';
    if(sum==2) ans='R';

    cout<<ans<<endl;
    
    return 0;
}