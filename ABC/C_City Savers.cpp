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

int N;
int A[100001];
int B[100000];

int main(){
    cin>>N;
    rep(i,N+1) cin>>A[i];
    rep(i,N) cin>>B[i];

    ll ans=0;
    rep(i,N){
        if(A[i]>=B[i]){
            ans+=B[i];
            A[i]-=B[i];
        }else{
            ans+=min(B[i],A[i]+A[i+1]);
            A[i+1]=max(A[i]+A[i+1]-B[i],0);
            A[i]=0;
        }
    }

    cout<<ans<<endl;
}