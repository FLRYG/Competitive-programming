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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

int N;
int a[100];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int ans=0;
    rep(i,N){
        if(i%2==0 && a[i]%2==1) ans++;
    }

    cout<<ans<<endl;
}