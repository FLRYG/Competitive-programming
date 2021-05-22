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

int N;

int main(){
    vector<double> v(11,0);
    v[0]=0.5;
    repn(i,10) v[i]=(2*v[i-1]*v[i-1]+3)/(3*v[i-1]*v[i-1]+5);
    rep(i,11) cout<<setprecision(16)<<i<<' '<<v[i]<<endl;


    cin>>N;
    vector<vector<ll>> cnt(3,vector<ll>(46,0));
    rep(i,3) rep(j,N){
        int a;
        cin>>a;
        cnt[i][a%46]++;
    }


    
    return 0;
}