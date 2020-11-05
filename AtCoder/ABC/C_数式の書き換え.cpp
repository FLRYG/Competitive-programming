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
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

string S;

int main(){
    cin>>S;
    S+='+';

    string t;
    int ans=0;
    rep(i,S.size()){
        if(S[i]!='+'){
            if(S[i]!='*') t+=S[i];
        }else{
            bool flag=true;
            rep(i,t.size()){
                if(t[i]=='0') flag=false;
            }
            if(flag) ans++;
            t.clear();
        }
    }

    cout<<ans<<endl;
}