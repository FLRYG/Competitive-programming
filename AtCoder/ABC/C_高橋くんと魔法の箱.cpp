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
int a[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    map<int,int> m;
    rep(i,N){
        while(a[i]%2==0) a[i]/=2;
        m[a[i]]++;
    }

    int ans=m.size();

    cout<<ans<<endl;
}