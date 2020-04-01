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

int N,M;
int K[30];
int A[30][30];
int res[31];

int main(){
    cin>>N>>M;
    rep(i,N){
        cin>>K[i];
        rep(j,K[i]){
            cin>>A[i][j];
            res[A[i][j]]++;
        }
    }

    int ans=0;
    repn(i,M){
        if(res[i]==N) ans++;
    }

    cout<<ans<<endl;
}