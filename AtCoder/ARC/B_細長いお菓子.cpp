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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    vector<int> cnt(100001);
    int l=0;
    int ans=0;
    int res=0;
    repn(r,N){
        cnt[A[r-1]]++;
        res++;
        while(cnt[A[r-1]]>=2){
            cnt[A[l]]--;
            l++;
            res--;
        }
        ans=max(ans,res);
    }

    cout<<ans<<endl;
    
    return 0;
}