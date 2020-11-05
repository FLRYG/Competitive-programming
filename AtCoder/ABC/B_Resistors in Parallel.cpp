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
double A[100];

int main(){
    cin>>N;
    double sum=0;
    rep(i,N){
        double a;
        cin>>a;
        A[i]=1/a;
        sum+=A[i];
    }

    double ans=1/sum;

    cout<<setprecision(10)<<ans<<endl;
}