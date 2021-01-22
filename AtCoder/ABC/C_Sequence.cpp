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
int a[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    ll cnt1=0, cnt2=0;
    ll sum=0;
    rep(i,N){
        sum+=a[i];
        if(i&1 && sum<=0){
            cnt1+=-sum+1;
            sum=1;
        }else if(!(i&1) && sum>=0){
            cnt1+=sum+1;
            sum=-1;
        }
    }
    
    sum=0;
    rep(i,N){
        sum+=a[i];
        if(i&1 && sum>=0){
            cnt2+=sum+1;
            sum=-1;
        }else if(!(i&1) && sum<=0){
            cnt2+=-sum+1;
            sum=1;
        }
    }

    cout<<min(cnt1,cnt2)<<endl;
}