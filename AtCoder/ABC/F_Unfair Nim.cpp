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
ll A[300];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    ll sum=0;
    rep(i,N) sum^=A[i];
    sum^=A[0]^A[1];

    ll ans=0;
    

}