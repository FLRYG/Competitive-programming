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
ll X[100000];
ll Y[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>X[i]>>Y[i];

    sort(X,X+N);
    sort(Y,Y+N);

    ll L=0, R=0;
    rep(i,N-1) R+=X[i+1]-X[0];

    ll xmin=R;
    rep(i,N-1){
        R-=(N-1-i)*(X[i+1]-X[i]);
        L+=(i+1)*(X[i+1]-X[i]);
        xmin=min(xmin,L+R);
    }

    L=0, R=0;
    rep(i,N-1) R+=Y[i+1]-Y[0];

    ll ymin=R;
    rep(i,N-1){
        R-=(N-1-i)*(Y[i+1]-Y[i]);
        L+=(i+1)*(Y[i+1]-Y[i]);
        ymin=min(ymin,L+R);
    }

    cout<<xmin+ymin<<endl;
    
    return 0;
}