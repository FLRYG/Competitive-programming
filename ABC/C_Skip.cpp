#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

template<class T>T gcd(T a, T b){if(a<b){a^=b;b^=a;a^=b;}return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a/gcd(a,b)*b;}

int N,X;
int x[100000];

int main(){
    cin>>N>>X;
    rep(i,N) cin>>x[i];

    int ans=0;
    rep(i,N){
        x[i]=abs(x[i]-X);
        ans=gcd(ans,x[i]);
    }
    
    cout<<ans<<endl;
}