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

int H,W;
int C[101][101];

int main(){
    cin>>H>>W;
    repn(i,H) repn(j,W) cin>>C[i][j];

    repn(i,H) repn(j,W) if((i+j)&1) C[i][j]*=-1;

    repn(i,H){
        repn(j,W){
            C[i][j]+=C[i-1][j]+C[i][j-1]-C[i-1][j-1];
        }
    }

    int ans=0;
    repn(i,H){
        repn(j,W){
            for(int k=i;k<=H;k++){
                for(int l=j;l<=W;l++){
                    int x=C[k][l]-C[k][j-1]-C[i-1][l]+C[i-1][j-1];
                    if(x==0){
                        ans=max(ans,(k-i+1)*(l-j+1));
                    }
                }
            }
        }
    }

    cout<<ans<<endl;
    
    return 0;
}