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

int N,L,K;
int A[100002];

int main(){
    cin>>N>>L>>K;
    repn(i,N) cin>>A[i];
    A[N+1]=L;

    vector<int> len(N+1,0);
    rep(i,N+1) len[i]=A[i+1]-A[i];
    // repr(e,len) cout<<e<<' '; cout<<endl;

    int ok=0, ng=INF;
    while(ng-ok>1){
        int m=(ok+ng)/2;
        int cnt=0;
        int l=0;
        rep(i,N+1){
            l+=len[i];
            if(l>m){
                cnt++;
                l=0;
                if(cnt==K+1) break;
            }
        }
        if(0<l && l<m) ng=m;
        else if(cnt==K+1) ok=m;
        else ng=m;
    }

    cout<<ok+1<<endl;

    return 0;
}