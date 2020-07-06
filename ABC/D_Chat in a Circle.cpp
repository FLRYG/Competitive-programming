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

ll N;
ll A[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    sort(A,A+N,greater<ll>());

    ll ans=A[0];
    N-=2;
    repn(i,(N+1)/2){
        if(2*i<=N) ans+=2*A[i];
        else ans+=A[i];
    }
    

    cout<<ans<<endl;
}