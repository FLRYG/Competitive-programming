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
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int H,W,N;
int a[10000];
int ans[100][100];

int main(){
    cin>>H>>W>>N;
    rep(i,N) cin>>a[i];

    int idx=0;
    rep(i,N){
        rep(j,a[i]){
            int r=idx/W;
            int c=idx%W;
            if(r&1) c=W-c-1;
            ans[r][c]=i+1;
            idx++;
        }
    }

    rep(i,H){
        rep(j,W) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
}