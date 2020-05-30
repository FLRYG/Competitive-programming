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

ll N;
ll A[100001];
ll B[100001];
ll sum[100002];

int main(){
    cin>>N;
    rep(i,N+1) cin>>A[i];
    for(int i=N;i>=0;i--){
        sum[i]=sum[i+1]+A[i];
    }

    B[0]=1-A[0];
    repn(i,N-1){
        
    }
}