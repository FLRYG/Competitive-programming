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

int N;
int F[100][10];
int P[100][11];

int main(){
    cin>>N;
    rep(i,N){
        rep(j,10){
            cin>>F[i][j];
        }
    }
    rep(i,N){
        rep(j,11){
            cin>>P[i][j];
        }
    }

    int ans=-1001001001;
    for(int i=1;i<1<<10;i++){
        int sum=0;
        rep(j,N){
            int c=0;
            rep(k,10){
                if(i>>k&F[j][k]) c++;
            }
            sum+=P[j][c];
        }
        ans=max(ans,sum);
    }

    cout<<ans<<endl;
}