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

int H,W;
char S[10][10];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>S[i][j];

    int ans=0;
    rep(i,H-1){
        rep(j,W-1){
            int b=0;
            rep(k,2){
                rep(l,2){
                    if(S[i+k][j+l]=='#') b++;
                }
            }
            if(b==1 || b==3) ans++;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}