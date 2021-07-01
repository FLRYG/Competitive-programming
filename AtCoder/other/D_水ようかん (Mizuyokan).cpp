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
int L[51];

int main(){
    cin>>N;
    repn(i,N) cin>>L[i];

    vector<int> sum(N+1,0);
    repn(i,N) sum[i]=L[i]+sum[i-1];

    int ans=INF;
    rep(l,N) for(int r=l+1;r<=N;r++){
        if(l==0 && r==N) continue;
        int t=sum[r]-sum[l];
        int len=0, sup=0, inf=INF;
        repn(i,N){
            if(len+L[i]<=t) len+=L[i];
            else{
                if(len==0) goto exit;
                sup=max(sup,len);
                inf=min(inf,len);
                len=0;
            }
        }
        sup=max(sup,len);
        inf=min(inf,len);
        ans=min(ans,sup-inf);
        cout<<l<<' '<<r<<' '<<t<<' '<<sup<<' '<<inf<<' '<<sup-inf<<endl;
        exit:;
    }

    cout<<ans<<endl;
    
    return 0;
}