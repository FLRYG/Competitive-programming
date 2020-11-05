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

int N,T;
int A[100000];

int main(){
    cin>>N>>T;
    rep(i,N) cin>>A[i];

    int l=0, r=0;
    int ans=0;
    rep(i,N){
        if(r<A[i]){
            ans+=r-l;
            l=A[i];
        }
        r=A[i]+T;
    }
    ans+=r-l;

    cout<<ans<<endl;
}