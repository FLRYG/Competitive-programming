#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,D;
int X[10][10];

int main(){
    cin>>N>>D;
    rep(i,N) rep(j,D) cin>>X[i][j];

    int ans=0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            int sum=0;
            rep(k,D){
                sum+=(X[i][k]-X[j][k])*(X[i][k]-X[j][k]);
            }
            int d1=sqrt(sum);
            double d2=sqrt(sum);

            if(d1==d2) ans++;
        }
    }

    cout<<ans<<endl;
}