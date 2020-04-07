#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const ll MOD=1'000'000'007;

ll N;
ll A[300000];

//O(N^2)
int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int ans=0;
    rep(i,N-1){
        for(int j=i+1;j<N;j++){
            ans+=(A[i]^A[j])%MOD;
            ans%=MOD;
        }
    }

    cout<<ans<<endl;
}