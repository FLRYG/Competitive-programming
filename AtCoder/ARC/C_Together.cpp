#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int a[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    vector<int> cnt(100000);
    rep(i,N) cnt[a[i]]++;

    int ans=0;
    repn(i,100000-1){
        ans=max(ans,cnt[i-1]+cnt[i]+cnt[i+1]);
    }

    cout<<ans<<endl;
    
    return 0;
}