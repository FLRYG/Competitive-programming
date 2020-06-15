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

ll N,M;
ll A[100][100];

int main(){
    cin>>N>>M;
    rep(i,N) rep(j,M) cin>>A[i][j];

    ll ans=0;
    rep(a,M-1){
        for(int b=a+1;b<M;b++){
            ll res=0;
            rep(i,N){
                res+=max(A[i][a],A[i][b]);
            }
            ans=max(ans,res);
        }
    }

    cout<<ans<<endl;
}