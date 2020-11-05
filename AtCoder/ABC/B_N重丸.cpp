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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int R[1000];

int main(){
    cin>>N;
    rep(i,N) cin>>R[i];

    sort(R,R+N,greater<int>());

    int r=0;
    rep(i,N){
        if(i&1) r-=R[i]*R[i];
        else r+=R[i]*R[i];
    }

    double ans=PI*r;

    cout<<setprecision(16)<<ans<<endl;
}