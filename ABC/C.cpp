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

int N;
int A[200001];

int main(){
    cin>>N;
    rep(i,N-1) cin>>A[i];

    int ans[200001];
    rep(i,N-1) ans[A[i]]++;

    repn(i,N) cout<<ans[i]<<endl;
}