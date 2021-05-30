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

ll mpow(ll x,ll n){
    if(n==0) return 1;
    else if(n%2) return x*mpow(x,n-1);
    return mpow(x*x,n/2);
}

int N,A,B,C;
int l[8];

int main(){
    cin>>N>>A>>B>>C;
    rep(i,N) cin>>l[i];

    int ans=INF;
    rep(i,mpow(4,N)){
        vector<int> a,b,c;
        int n=i;
        rep(j,N){
            if(n%4==0) a.push_back(l[j]);
            else if(n%4==1) b.push_back(l[j]);
            else if(n%4==2) c.push_back(l[j]);
            n/=4;
        }
        if(a.size()==0 || b.size()==0 || c.size()==0) continue;
        int res=10*(a.size()+b.size()+c.size()-3);
        int sum;
        sum=0; repr(e,a) sum+=e; res+=abs(sum-A);
        sum=0; repr(e,b) sum+=e; res+=abs(sum-B);
        sum=0; repr(e,c) sum+=e; res+=abs(sum-C);
        ans=min(ans,res);
    }

    cout<<ans<<endl;
    
    return 0;
}