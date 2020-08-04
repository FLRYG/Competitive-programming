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
ll const MOD=1'000'000'007;

int N,A,B,C,D;
string S;

int main(){
    cin>>N>>A>>B>>C>>D>>S;

    bool flag=true;
    if(C<D){
        rep(i,D-B-1){
            flag&=(S[B+i-1]=='.' || S[B+i]=='.');
        }
        S[D-1]='#';
        rep(i,C-A-1){
            flag&=(S[A+i-1]=='.' || S[A+i]=='.');
        }
    }else{
        bool f=false;
        rep(i,D-B+1){
            if(S[B+i-1]=='.' && S[B+i]=='.' && S[B+i+1]=='.') f=true;
        }
        flag&=f;
    }

    string ans;
    if(flag) ans="Yes";
    else ans="No";

    cout<<ans<<endl;
}