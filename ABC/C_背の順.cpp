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
typedef pair<int,int> P;
ll const MOD=1000000007;

int N; 
P a[100000];

int main(){
    cin>>N;
    rep(i,N) a[i].second=i+1;
    rep(i,N) cin>>a[i].first;

    sort(a,a+N,greater<>());

    rep(i,N) cout<<a[i].second<<endl;
}