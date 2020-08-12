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
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N;
string S[50];

int main(){
    cin>>N;
    rep(i,N) cin>>S[i];

    map<string,int> m;
    rep(i,N){
        m[S[i]]++;
    }

    int cnt=0;
    string ans;
    repr(e,m){
        if(e.second>cnt){
            cnt=e.second;
            ans=e.first;
        }
    }

    cout<<ans<<endl;
}