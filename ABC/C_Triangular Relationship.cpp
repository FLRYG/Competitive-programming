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

int main(){
    cin>>N>>K;

    ll ans=(N/K)*(N/K)*(N/K);
    if(K%2==0){
        ll x=N%K>=K/2?N/K+1:N/K;
        ans+=x*x*x;
    }

    cout<<ans<<endl;
}