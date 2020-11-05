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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int A,B;

int main(){
    cin>>A>>B;

    int ans=A-B;
    repn(a,999){
        if(a<100) continue;
        bool f=0;
        if(A%100==a%100 || (A/100==a/100 && A%10==a%10)
        || A/10==a/10) f=1; 
        repn(b,999){
            if(b<100) continue;
            bool g=0;
            if(B%100==b%100 || (B/100==b/100 && B%10==b%10)
            || B/10==b/10) g=1;
            if(f==1 && g==0) ans=max(ans,a-B); 
            if(f==0 && g==1) ans=max(ans,A-b); 
        }
    }

    cout<<ans<<endl;
}