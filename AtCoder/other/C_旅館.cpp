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
ll const MOD=1000000007;

int N,M;
int A[100001], B[100001];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];

    sort(A,A+N);
    sort(B,B+M);

    int a=0, b=0;
    rep(a,N){
        if(b<M && B[b]<=A[a]) b++;
    }

    string ans;
    if(b==M) ans="YES";
    else ans="NO";

    cout<<ans<<endl;
}