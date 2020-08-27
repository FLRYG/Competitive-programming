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

int N;
string s,t;

int main(){
    cin>>N>>s>>t;

    int ans=0;
    rep(i,N){
        for(int j=i;j<N;j++){
            if(s[j]!=t[j-i]) goto a;
        }
        ans=N-i;
        break;
        a:;
    }

    ans=2*N-ans;
    cout<<ans<<endl;
}