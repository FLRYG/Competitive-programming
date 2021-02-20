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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string const &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

string f(ll x){
    string res;
    while(x>0){
        res+=x%10+'0';
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

string X;
ll M;

int main(){
    cin>>X>>M;
    int N=X.size();


    ll d=0;
    rep(i,N) d=max(d,(ll)(X[i]-'0'));

    ll l=d, r=1e18; r++;
    // __int128 l=parse(f(d)), r=parse(f((ll)1e18+1)); r++;
    while(r-l>1){
        ll y=0;
        ll mid=(l+r)/2;
        // __int128 mid=(l+r)/2;
        rep(i,N){
            y*=mid;
            y+=X[i]-'0';
            // cout<<y<<endl;
            if(y>M){
                r=mid;
                cout<<mid<<' '<<y<<endl;
                goto a;
            }
        }
        cout<<mid<<' '<<y<<endl;
        l=mid;
        a:;
    }
    ll ans=l-d;

    cout<<ans<<endl;
    
    return 0;
}