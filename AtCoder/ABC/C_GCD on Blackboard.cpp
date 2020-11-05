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

template<class T>T gcd(T a, T b){if(a<b){a^=b;b^=a;a^=b;}return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a*b/gcd(a,b);}

int N;
int A[100002];
int L[100002];
int R[100002];

int main(){
    cin>>N;
    repn(i,N){
        cin>>A[i];
    }

    repn(i,N){
        L[i+1]=gcd(L[i],A[i]);
        R[N-i+1]=gcd(R[N-i+2],A[N-i+1]);
    }

    int ans=0;
    repn(i,N){
        ans=max(ans,gcd(L[i],R[i+1]));
        //cout<<"i="<<i<<' '<<L[i]<<','<<R[i+1]<<endl;
    }

    cout<<ans<<endl;
}