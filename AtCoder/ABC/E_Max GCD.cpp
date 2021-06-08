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
typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,K;
int A[500];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>A[i];

    int sum=0;
    rep(i,N) sum+=A[i];

    int ans=1;
    repn(n,sqrt(sum)){
        if(sum%n!=0) continue;
        vector<int> m={n,sum/n};
        rep(k,2){
            vector<int> a(N+1);
            repn(i,N) a[i]=A[i-1]%m[k];
            sort(a.begin(),a.end());
            repn(i,N) a[i]+=a[i-1];
            rep(i,N+1){
                if(a[i]==m[k]*(N-i)-(a[N]-a[i]) && a[i]<=K){
                    ans=max(ans,m[k]);
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;
    
    return 0;
}