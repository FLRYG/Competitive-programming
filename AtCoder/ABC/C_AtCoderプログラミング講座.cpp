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
using namespace std;
typedef long long ll;

int N,K;
double R[100];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>R[i];

    sort(R,R+N);

    double ans=0;
    for(int i=N-K;i<N;i++){
        ans=(ans+R[i])/2;
    }

    cout<<setprecision(16)<<ans<<endl;
}