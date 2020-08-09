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

int N;
int A[100000];
bool flag[100001];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int ans=0;
    rep(i,N){
        if(flag[A[i]]) ans++;
        flag[A[i]]=true;
    }

    cout<<ans<<endl;
}