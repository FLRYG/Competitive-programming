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

int N,K;

int main(){
    cin>>N>>K;

    vector<int> cnt(N+1,0);
    int ans=0;
    for(int i=2;i<=N;i++){
        if(cnt[i]==0){
            for(int j=i;j<=N;j+=i){
                cnt[j]++;
            }
        }
        if(cnt[i]>=K) ans++;
    }

    cout<<ans<<endl;
    
    return 0;
}