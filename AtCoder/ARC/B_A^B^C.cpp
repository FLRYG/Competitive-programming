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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

ll mpow(ll x, ll n, ll MOD){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1,MOD)%MOD;
    return mpow(x*x%MOD,n/2,MOD)%MOD;
}

ll A,B,C;

int main(){
    cin>>A>>B>>C;

    int ans;
    int x=A%10;
    if(x==0 || x==1 || x==5 || x==6) ans=x;
    else if(x==4 || x==9){
        ll m=mpow(B,C,2);
        if(m==0) m=2;
        ans=mpow(A,m,10);
    }else if(x==2 || x==3 || x==7 || x==8){
        ll m=mpow(B,C,4);
        if(m==0) m=4;
        ans=mpow(A,m,10);
    }

    cout<<ans<<endl;
    
    return 0;
}