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
int a[100000];

int main(){
    cin>>N>>K;
    rep(i,N) cin>>a[i];

    int ans=0, cnt=0, r=0;
    map<int,int> m;
    rep(l,N){
        while(cnt<=K && r<N){
            if(cnt<K){
                if(m[a[r]]==0) cnt++;
                m[a[r]]++;
            }else{
                if(m[a[r]]==0) break;
                else m[a[r]]++;
            }
            r++;
        }
        ans=max(ans,r-l);
        m[a[l]]--;
        if(m[a[l]]==0) cnt--;
    }

    cout<<ans<<endl;
    
    return 0;
}