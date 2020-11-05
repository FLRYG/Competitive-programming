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

ll K,N;
ll A[200000];

int main(){
    cin>>K>>N;
    rep(i,N) cin>>A[i];

    sort(A,A+N);

    ll max_d=K-A[N-1]+A[0];
    for(int i=0;i<N;i++){
        max_d=max(max_d,A[i+1]-A[i]);
    }

    ll ans=K-max_d;

    cout<<ans<<endl;
}