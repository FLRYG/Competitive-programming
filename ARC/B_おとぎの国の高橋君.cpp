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

int b[10];
int N;
int a[777];
int c[10];

int main(){
    rep(i,10) cin>>b[i];
    cin>>N;
    rep(i,N) cin>>a[i];
    rep(i,10) c[b[i]]=i;
    
    rep(i,N){
        int ten=1;
        rep(j,log10(a[i])+1){
            int bef=a[i]/ten%10;
            int aft=c[bef];
            a[i]=a[i]+ten*(aft-bef);
            ten*=10;
        }
    }
    sort(a,a+N);
    rep(i,N){
        int ten=1;
        rep(j,log10(a[i])+1){
            int bef=a[i]/ten%10;
            int aft=b[bef];
            a[i]=a[i]+ten*(aft-bef);
            ten*=10;
        }
    }

    rep(i,N) cout<<a[i]<<endl;
}