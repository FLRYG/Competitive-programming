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
ll K;

int main(){
    cin>>S>>K;

    bool flag=true;
    rep(i,S.size()) flag&=(S[0]==S[i]);

    ll ans=0;
    if(flag){
        ans=K*S.size()/2;
        cout<<ans<<endl;
        return 0;
    }

    ll cnt=1;
    rep(i,S.size()-1){
        if(S[i]==S[i+1]) cnt++;
        else{
            ans+=cnt/2;
            cnt=1;
        }
    }
    ans+=cnt/2;
    ans*=K;
    
    if(S[0]==S[S.size()-1]){
        int l=0,r=0;
        rep(i,S.size()){
            if(S[i]==S[0]) l++;
            else break;
        }
        rep(i,S.size()){
            if(S[S.size()-1-i]==S[S.size()-1]) r++;
            else break;
        }
        ans+=(K-1)*((l+r)/2-l/2-r/2);
    }

    cout<<ans<<endl;
}