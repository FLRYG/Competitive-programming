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
string S;

int main(){
    cin>>N>>K>>S;

    int ans=INF;
    int J=0, O=0, I=0;
    int rj=0, ro=0, ri=0;
    rep(l,N){
        rj=max(rj,l);
        while(rj<N && J<K){
            if(S[rj]=='J') J++;
            if(rj<ro && S[rj]=='O') O--;
            if(ro<=rj && rj<ri && S[rj]=='I') I--;
            rj++;
        }
        ro=max(ro,rj);
        while(ro<N && O<K){
            if(S[ro]=='O') O++;
            if(ro<ri && S[ro]=='I') I--;
            ro++;
        }
        ri=max(ri,ro);
        while(ri<N && I<K){
            if(S[ri]=='I') I++;
            ri++;
        }

        // cout<<l<<' '<<rj<<' '<<ro<<' '<<ri<<' '<<J<<' '<<O<<' '<<I<<endl;
        if(J>=K && O>=K && I>=K) ans=min(ans,ri-l-3*K);
        if(S[l]=='J') J--;
    }
    if(ans==INF) ans=-1;

    cout<<ans<<endl;
    
    return 0;
}