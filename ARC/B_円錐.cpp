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

const double PI=3.14159'26535'89793;

int N,Q;
ld X[100],R[100],H[100];
ld A[100],B[100];

int main(){
    cin>>N>>Q;
    rep(i,N) cin>>X[i]>>R[i]>>H[i];
    rep(i,Q) cin>>A[i]>>B[i];

    vector<double> V(N);
    rep(i,N){
        V[i]=PI*R[i]*R[i]/3*H[i];
    }

    rep(i,Q){
        ld ans=0;
        rep(j,N){
            if(A[i]<=X[j] && X[j]+H[j]<=B[i]){
                ans+=V[j];
            }else if(X[j]<=A[i] && X[j]+H[j]<=B[i]){
                ans+=V[j]*pow((X[j]+H[j]-A[i])/H[j],3);
            }else if(A[i]<=X[j] && B[i]<=X[j]+H[j]){
                ans+=V[j]*(1-pow((X[j]+H[j]-B[i])/H[j],3));
            }else if(X[j]<=A[i] && B[i]<=X[j]+H[j]){
                ans+=V[j]*pow((X[j]+H[j]-A[i])/H[j],3)*(1-pow((X[j]+H[j]-B[i])/(H[j]-A[i]),3));
            }
        }
        cout<<setprecision(16)<<ans<<endl;
    }
}