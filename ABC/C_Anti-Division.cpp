#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

template<class T>
T gcd(T a, T b){
    if(a<b){a^=b;b^=a;a^=b;}
    return b?gcd(b,a%b):a;
}
template<class T>
T lcm(T a, T b){
    return a*b/gcd(a,b);
}


ll A,B,C,D;

int main(){
    cin>>A>>B>>C>>D;

    ll x=lcm(C,D);
    ll ans=B-A+1-(B/C-(A-1)/C)-(B/D-(A-1)/D)+(B/x-(A-1)/x);

    cout<<ans<<endl;
}