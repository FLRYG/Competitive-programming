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

int N;
int A[200000];
int B[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i]>>B[i];

    sort(A,A+N);
    sort(B,B+N);

    int ans=0;
    if(N&1){
        ans=B[N/2]-A[N/2]+1;
    }else{
        int ma=A[N/2-1]+A[N/2];
        int mb=B[N/2-1]+B[N/2];
        ans=mb-ma+1;
    }

    cout<<ans<<endl;
}