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

int N,M,C;
int B[20];
int A[20][20];

int main(){
    cin>>N>>M>>C;
    rep(i,M) cin>>B[i];
    rep(i,N) rep(j,M) cin>>A[i][j];

    int ans=0;
    rep(i,N){
        int sum=C;
        rep(j,M){
            sum+=A[i][j]*B[j];
        }
        if(sum>0) ans++;
    }

    cout<<ans<<endl;
}