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

int N;
int d[500];

int main(){
    cin>>N;
    rep(i,N) cin>>d[i];

    int maxi=0, mini=0;
    rep(i,N) maxi+=d[i];
    rep(i,N){
        if(d[i]>=(maxi-d[i])){
            mini=2*d[i]-maxi;
            break;
        }
    }

    cout<<maxi<<endl;
    cout<<mini<<endl;
}