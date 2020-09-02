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

int N,C;
int D[31][31];
int c[501][501];
int sum[3][31];

int main(){
    cin>>N>>C;
    repn(i,C) repn(j,C) cin>>D[i][j];
    repn(i,N) repn(j,N) cin>>c[i][j];

    repn(i,N){
        repn(j,N){
            repn(k,C){
                sum[(i+j)%3][k]+=D[c[i][j]][k];
            }
        }
    }

    int ans=INF;
    repn(i,C){
        repn(j,C){
            if(i==j) continue;
            repn(k,C){
                if(i==k || j==k) continue;
                ans=min(ans,sum[0][i]+sum[1][j]+sum[2][k]);
            }
        }
    }

    cout<<ans<<endl;
}