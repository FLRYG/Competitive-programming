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
int W[100];
int S1=0, S2=0;

int main(){
    cin>>N;
    rep(i,N){
        cin>>W[i];
        S2+=W[i];
    }

    int ans=100100;
    rep(i,N){
        S1+=W[i];
        S2-=W[i];
        if(abs(S1-S2)<ans) ans=abs(S1-S2);
    }

    cout<<ans<<endl;
}