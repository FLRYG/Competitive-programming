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
ll const MOD=1000000007;

int N;
string s[100];

int main(){
    cin>>N;
    rep(i,N) cin>>s[i];

    rep(i,N) reverse(s[i].begin(),s[i].end());
    sort(s,s+N);
    rep(i,N) reverse(s[i].begin(),s[i].end());

    rep(i,N){
        cout<<s[i]<<endl;
    }
}