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
int P[20];

int main(){
    cin>>N;
    rep(i,N) cin>>P[i];

    int ans=0;
    for(int i=1;i<N-1;i++){
        if(P[i-1]<P[i] && P[i]<P[i+1] ||
        P[i-1]>P[i] && P[i]>P[i+1]) ans++;
    }

    cout<<ans<<endl;
}