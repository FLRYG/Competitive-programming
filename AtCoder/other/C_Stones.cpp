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

int N;
string S;
int w[200001], b[200001];

int main(){
    cin>>N>>S;

    int ans=1001001001;
    rep(i,N){
        w[i+1]=w[i], b[i+1]=b[i];
        if(S[i]=='.') w[i+1]++;
        else b[i+1]++;
    }
    rep(i,N+1){
        ans=min(ans,b[i]+(w[N]-w[i]));
    }

    cout<<ans<<endl;
}