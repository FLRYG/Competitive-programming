#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

template<class T>T gcd(T a, T b){if(a<b){a^=b;b^=a;a^=b;}return b?gcd(b,a%b):a;}
template<class T>T lcm(T a, T b){return a*b/gcd(a,b);}

int N;
int A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int ans=0;
    rep(i,N){
        ans=gcd(ans,A[i]);
    }

    cout<<ans<<endl;
}