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
//typedef pair<ll,ll> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll S;
ll X[3];
ll Y[3];

int main(){
    cin>>S;

    X[1]=Y[2]=(ll)ceil(sqrt(S));
    Y[1]=1;
    X[2]=X[1]*Y[2]-S;

    rep(i,3) cout<<X[i]<<' '<<Y[i]<<' ';
    cout<<endl;

    //cout<<abs(X[1]*Y[2]-Y[1]*X[2])<<endl;
}