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

ll N;
ll A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];
    if(N==1){
        cout<<A[0]/2<<endl;
        return 0;
    }

    ll ans=0;
    ll x=A[0];
    repn(i,N-1){
        x+=A[i];
        ans+=x/2;
        x%=2;
        if(A[i]==0) x=0;
    }

    cout<<ans<<endl;
}