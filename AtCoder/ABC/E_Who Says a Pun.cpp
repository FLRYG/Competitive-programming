#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
string S;

int main(){
    cin>>N>>S;

    int ans=0;
    vector<int> dp(N,0);
    for(int i=N-1;i>=0;i--){
        vector<int> v(N);
        for(int j=i;j>=0;j--){
            if(S[i]==S[j]) v[j]=dp[j+1]+1;
            ans=max(ans,min(i-j,v[j]));
        }
        dp=v;
    }

    cout<<ans<<endl;
    
    return 0;
}