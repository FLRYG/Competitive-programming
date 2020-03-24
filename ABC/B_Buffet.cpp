#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int N;
int A[20],B[20],C[20];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    rep(i,N-1) cin>>C[i];

    int k=100;
    int ans=0;
    rep(i,N){
        ans+=B[A[i]-1];
        if(A[i]-k==1) ans+=C[k-1];
        k=A[i];
    }

    cout<<ans<<endl;
}