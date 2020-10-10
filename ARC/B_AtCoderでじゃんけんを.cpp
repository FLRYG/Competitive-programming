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
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
int R[100000];
int H[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>R[i]>>H[i];
    rep(i,N) H[i]--;

    vector<int> cnt(100000+1);
    rep(i,N) cnt[R[i]]++;
    rep(i,100000) cnt[i+1]+=cnt[i];
    
    map<P,int> m;
    rep(i,N) m[P(R[i],H[i])]++;

    rep(i,N){
        int a=0, b=0, c=0;
        a+=cnt[R[i]-1];
        a+=m[P(R[i],(H[i]+1)%3)];
        b+=cnt[100000]-cnt[R[i]];
        b+=m[P(R[i],(H[i]+2)%3)];
        c+=m[P(R[i],H[i])]-1;
        cout<<a<<' '<<b<<' '<<c<<endl;
    }
}