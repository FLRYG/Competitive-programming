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
ll const MOD=1'000'000'007;

int main(){
    int N;
    cin>>N;

    ll a=1,b=1;
    rep(i,N){
        ll tmp=a;
        a=a+b;
        b=tmp;
    }

    cout<<a<<' '<<b<<endl;
}