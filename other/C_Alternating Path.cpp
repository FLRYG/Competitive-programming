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
typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int H,W;
string S[400];

int main(){
    cin>>S>>W;
    rep(i,H) cin>>S[i];

    queue<P> q;
    ll ans=0;
    rep(i,H) rep(j,W){
        if(S[i][j]=='#'){
            int chk[400][400];
            q.push(P(i,j));
            while(!q.empty()){
                P p=q.front(); q.pop();
            }
        }
    }


}