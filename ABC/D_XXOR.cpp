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

ll N,K;
ll A[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    ll one[40];
    rep(i,40) one[i]=0;
    for(ll i=0;i<40;i++){
        rep(j,N){
            if(A[j]>>i&1) one[i]++;
        }
    }

    ll ans=0;
    for(ll i=39;i>=0;i--){
        if(one[i]<N-one[i] && K-((ll)1<<i)>=0){
            ans+=((ll)1<<i)*(N-one[i]);
            K-=((ll)1<<i);
        }else{
            ans+=((ll)1<<i)*one[i];
        }
    }

    cout<<ans<<endl;
}