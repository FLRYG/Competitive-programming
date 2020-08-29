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

int c[3][3];
int a[3], b[3];

int main(){
    rep(i,3) rep(j,3) cin>>c[i][j];

    string ans="No";
    for(int n=-100;n<=100;n++){
        a[0]=n;
        rep(j,3) b[j]=c[0][j]-a[0];
        rep(i,3) a[i]=c[i][0]-b[0];
        repn(i,2){
            repn(j,2){
                if(a[i]+b[j]!=c[i][j]) goto a;
            }
        }
        ans="Yes";
        break;
        a:;
    }

    cout<<ans<<endl;
}