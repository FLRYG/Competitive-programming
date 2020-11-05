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

string S;
int T;
int X,Y,Q;

int main(){
    cin>>S>>T;

    rep(i,S.size()){
        if(S[i]=='L') X--;
        if(S[i]=='R') X++;
        if(S[i]=='U') Y++;
        if(S[i]=='D') Y--;
        if(S[i]=='?') Q++;
    }

    int ans=0;
    if(T==1){
        ans+=abs(X)+abs(Y)+abs(Q);
    }else{
        ans+=abs(X)+abs(Y)-abs(Q);
        if(ans<0){
            ans=abs(ans);
            if(ans%2==1) ans=1;
            else ans=0;
        }
    }

    cout<<ans<<endl;
}