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

string s;
int k;

int main(){
    cin>>s>>k;

    if(k>s.size()){
        cout<<0<<endl;
        return 0;
    }

    map<string,int> m;
    rep(i,s.size()-k+1){
        string t;
        rep(j,k){
            t+=s[i+j];
        }
        m[t]=1;
    }

    int ans=m.size();
    cout<<ans<<endl;
}