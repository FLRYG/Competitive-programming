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

int main(){
    int N=13;

    vector<vector<char>> ans(N,vector<char>(N));
    int cnt=0;
    rep(n,2*N-1){
        rep(i,n+1){
            if(0<=i && i<N && 0<=n-i && n-i<N) ans[i][n-i]='a'+cnt%26;
            cnt++;
        }
    }

    cout<<N<<endl;
    rep(i,N){rep(j,N)cout<<ans[i][j];cout<<endl;}
}