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
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
ll const MOD=1'000'000'007;

int N;
int A[100];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int ans=1001001001;
    for(int i=-100;i<=100;i++){
        int sum=0;
        rep(j,N){
            sum+=(A[j]-i)*(A[j]-i);
        }
        ans=min(ans,sum);
    }

    cout<<ans<<endl;
}