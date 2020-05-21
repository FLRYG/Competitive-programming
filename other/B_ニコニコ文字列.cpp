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
typedef pair<int,int> P;

string S;

int main(){
    cin>>S;

    ll ans=0;
    ll cnt=0;
    rep(i,S.size()){
        if(S[i]=='2' && S[i+1]=='5'){
            cnt++;
            i++;
        }else{
            if(cnt>0){
                ans+=(cnt+1)*cnt/2;
                cnt=0;
            }
        }
    }
    if(cnt>0){
        ans+=(cnt+1)*cnt/2;
        cnt=0;
    }

    cout<<ans<<endl;
}