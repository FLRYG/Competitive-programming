#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

const int sign[2]={1,-1};

int N;
int A[100000];
int ans[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    rep(i,N){
        ans[0]+=A[i]*sign[i%2];
    }

    for(int i=1;i<N;i++){
        ans[i]=2*(A[i-1]-ans[i-1]/2);
    }

    rep(i,N) cout<<ans[i]<<' ';
    cout<<endl;
}