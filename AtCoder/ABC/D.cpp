#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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

int N;
string S[60];
ll dpx[61][2];
ll dpy[61][2];

int main(){
    cin>>N;
    rep(i,N) cin>>S[i];

    dpy[0][0]=1;
    dpy[0][1]=1;
    repn(i,N){
        if(S[i-1]=="AND"){
            dpy[i][0]=dpy[i-1][0]
            dpy[i][1]=dpy[i-1][1]*dpx[i-1][1];
        }
        else ans*=2;
    }
    
    return 0;
}