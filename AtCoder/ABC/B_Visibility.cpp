#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int H,W,X,Y;
char S[102][102];

int main(){
    cin>>H>>W>>X>>Y;
    rep(i,102) rep(j,102) S[i][j]='#';
    repn(i,H) repn(j,W) cin>>S[i][j];

    rep(i,H){
        if(S[i+X][Y]!='#') S[i+X][Y]='o';
        else break;
    }
    rep(i,H){
        if(S[X-i][Y]!='#') S[X-i][Y]='o';
        else break;
    }
    rep(i,W){
        if(S[X][Y+i]!='#') S[X][Y+i]='o';
        else break;
    }
    rep(i,W){
        if(S[X][Y-i]!='#') S[X][Y-i]='o';
        else break;
    }

    int ans=0;
    repn(i,H) repn(j,W) if(S[i][j]=='o') ans++;

    cout<<ans<<endl;

    return 0;
}