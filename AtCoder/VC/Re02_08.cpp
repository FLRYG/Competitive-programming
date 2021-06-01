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
int D[50];

int main(){
    cin>>N;
    rep(i,N) cin>>D[i];

    sort(D,D+N);

    vector<int> cnt(24,0);
    cnt[0]++;
    rep(i,N){
        if(i&1) cnt[max(D[i],24-D[i])%24]++;
        else cnt[min(D[i],24-D[i])%24]++;
    }

    int ans=INF, k=INF;
    rep(i,24){
        k++;
        if(cnt[i]==1){
            ans=min(ans,k);
            k=0;
        }
        if(cnt[i]>=2){
            ans=0;
            break;
        }
    }
    ans=min(ans,k+1);

    cout<<ans<<endl;
    
    return 0;
}