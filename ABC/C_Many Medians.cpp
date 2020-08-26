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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int X[200000];
int Y[200000];

int main(){
    cin>>N;
    rep(i,N) cin>>X[i];
    rep(i,N) Y[i]=X[i];

    sort(Y,Y+N);

    rep(i,N){
        
        int ans;
        if(X[i]<=Y[(N-1)/2]) ans=Y[N/2];
        else ans=Y[(N-1)/2];
        cout<<ans<<endl;
    }
}