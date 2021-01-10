#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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
int A[700000];

int main(){
    cin>>N;
    rep(i,1<<N) cin>>A[i];

    int l=0, lp=0;
    int r=0, rp=0;
    rep(i,1<<(N-1)){
        if(A[i]>l){
            l=A[i];
            lp=i;
        }
        if(A[i+(1<<(N-1))]>r){
            r=A[i+(1<<(N-1))];
            rp=i+(1<<(N-1));
        }
    }

    int ans;
    if(l>r) ans=rp;
    else ans=lp;
    ans++;

    cout<<ans<<endl;
    
    return 0;
}