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

string S;

int main(){
    cin>>S;

    int cnt=0;
    bool flag=false;
    rep(i,S.size()){
        if(S[i]=='{') cnt++;
        if(S[i]=='}') cnt--;
        if(cnt==1 && S[i]==':'){
            flag=true;
            break;
        }
    }
    if(S=="{}") flag=true;

    string ans;
    if(flag) ans="dict";
    else ans="set";

    cout<<ans<<endl;
}