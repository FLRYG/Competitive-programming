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
int A[5000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    ll ans=0;
    rep(j,N){
        int l=0, r=0;
        for(int i=0;i<j;i++){
            if(A[i]<A[j]) l++;
        }
        for(int k=j+1;k<N;k++){
            if(A[j]>A[k]) r++;
        }
        ans+=l*r;
    }

    cout<<ans<<endl;
    
    return 0;
}