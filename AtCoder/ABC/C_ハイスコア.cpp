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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N,M;

int main(){
    cin>>N>>M;

    int sum=0;
    vector<int> scr(M+2,0);
    rep(i,N){
        int l,r,s;
        cin>>l>>r>>s;
        sum+=s;
        scr[l]+=s;
        scr[r+1]-=s;
    }
    repn(i,M) scr[i]+=scr[i-1];

    int ans=0;
    repn(i,M) ans=max(ans,sum-scr[i]);

    cout<<ans<<endl;
    
    return 0;
}