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

int main(){
    cin>>N;

    ll ans=0;
    repn(i,N){
        ll n=N/i;
        ans+=i*n*(n+1)/2;
    }

    cout<<ans<<endl;
}

//O(√N)も可