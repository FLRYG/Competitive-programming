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
double x[10];
string u[10];

int main(){
    cin>>N;
    rep(i,N) cin>>x[i]>>u[i];

    double ans=0;
    rep(i,N){
        if(u[i]=="JPY"){
            ans+=x[i];
        }else{
            ans+=380000.0*x[i];
        }
    }

    cout<<setprecision(16)<<ans<<endl;
}