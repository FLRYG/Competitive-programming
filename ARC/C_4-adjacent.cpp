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
ll const MOD=1000000007;

int N;
int a[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int zero=0,two=0,four=0;
    rep(i,N){
        if(a[i]%4==0) four++;
        else if(a[i]%2==0) two++;
        else zero++;
    }

    string ans;
    if(zero<=four || (zero-1==four && two==0)) ans="Yes";
    else ans="No";

    cout<<ans<<endl;
}