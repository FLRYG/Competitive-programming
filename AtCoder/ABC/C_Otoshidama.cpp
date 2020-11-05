#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll const MOD=1000000007;

ll N,Y;

int main(){
    cin>>N>>Y;

    ll a=-1, b=-1, c=-1;
    rep(i,N+1){
        ll m=N-i;
        rep(j,m+1){
            ll k=m-j;
            if(10000*i+5000*j+1000*k==Y){
                a=i;
                b=j;
                c=k;
                break;
            }
        }
    }

    cout<<a<<' '<<b<<' '<<c<<endl;
}