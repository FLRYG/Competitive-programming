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

double N,K;

int main(){
    cin>>N>>K;

    double ans=0;
    repn(i,N){
        double x=max(ceil(log2(K/i)),0.0);
        ans+=1/pow(2,x);
    }
    ans/=N;

    cout<<setprecision(16)<<ans<<endl;
}