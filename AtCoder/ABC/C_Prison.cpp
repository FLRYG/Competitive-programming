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
int L[100000],R[100000];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>L[i]>>R[i];

    int l=0,r=100100;
    rep(i,M){
        if(l<L[i]) l=L[i];
        if(R[i]<r) r=R[i];

        if(r-l<0){
            cout<<0<<endl;
            return 0;
        }
    }
    int ans=r-l+1;

    cout<<ans<<endl;
}