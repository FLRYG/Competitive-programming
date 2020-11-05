#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
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

int N;
int A[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    map<int,int> m;
    ll ans=0;
    rep(i,N){
        ll k=(i+1)-A[i];
        ll l=(i+1)+A[i];
        ans+=m[k];
        m[l]++;
    }

    cout<<ans<<endl;
}