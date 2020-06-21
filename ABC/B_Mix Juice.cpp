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

int N,K;
int p[1000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>p[i];

    sort(p,p+N);

    int ans=0;
    rep(i,K){
        ans+=p[i];
    }

    cout<<ans<<endl;
}