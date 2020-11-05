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
int D[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>D[i];

    sort(D,D+N);

    int ans=D[N/2]-D[N/2-1];

    cout<<ans<<endl;
}