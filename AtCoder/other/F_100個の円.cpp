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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N=10;
int r[10];
int sum[10];
int p[10];
int X[100];
int Y[100];

int main(){
    rep(i,N) r[i]=100-i*i;
    rep(i,N) sum[i]=2*r[i];
    rep(i,N-1) sum[i+1]+=sum[i];
    rep(i,N) p[i]=sum[i]-r[i];

    // rep(i,N) cout<<sum[i]<<' ';cout<<endl;
    // rep(i,N) cout<<p[i]<<' ';cout<<endl;

    int idx=99;
    rep(i,10){
        rep(j,i+1){
            X[idx]=p[i];
            Y[idx--]=r[i]*(2*j+1);
        }
        rep(j,i){
            X[idx]=r[i]*(2*j+1);
            Y[idx--]=p[i];
        }
    }

    rep(i,100){
        cout<<X[i]<<' '<<Y[i]<<endl;
    }
    
    return 0;
}