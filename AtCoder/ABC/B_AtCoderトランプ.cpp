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

string S,T;

int main(){
    cin>>S>>T;

    bool flag=true;
    rep(i,S.size()){
        if(S[i]==T[i]) continue;
        if(S[i]=='@' || T[i]=='@'){
            string U;
            if(S[i]!='@') U=S;
            else U=T;
            if(U[i]=='a' || U[i]=='t' || U[i]=='c' || U[i]=='o' 
            || U[i]=='d' || U[i]=='e' || U[i]=='r') flag=true;
            else{
                flag=false;
                break;
            }
        }else{
            flag=false;
            break;
        }
    }

    string ans;
    if(flag) ans="You can win";
    else ans="You will lose";

    cout<<ans<<endl;
}