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

int A,B,K;

int main(){
    cin>>A>>B>>K;

    map<int,int> m;
    rep(i,K) m[A+i]++;
    rep(i,K) m[B-i]++;

    repr(e,m){
        int ans=e.first;
        if(A<=ans && ans<=B) cout<<ans<<endl;
    }
    
    return 0;
}