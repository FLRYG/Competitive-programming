#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,M;
int A[10000];

int main(){
    cin>>N>>M;
    rep(i,M) cin>>A[i];

    int ans=N;
    rep(i,M){
        ans-=A[i];
    }
    ans=max(ans,-1);

    cout<<ans<<endl;
}