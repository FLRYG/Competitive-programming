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
int x[1000];
int y[1000];
int c[1000];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>y[i]>>c[i];

    double ans=0;
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            int d=max(abs(x[i]-x[j]),abs(y[i]-y[j]));
            ans=max(ans,d*(double)(c[i]*c[j])/(c[i]+c[j]));
        }
    }

    cout<<setprecision(16)<<ans<<endl;
    
    return 0;
}