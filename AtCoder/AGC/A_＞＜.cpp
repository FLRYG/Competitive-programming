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
    char prev='0';
    ll l=0, r=0;    // l:< , r:>
    rep(i,S.size()){
        if(prev=='>' && S[i]=='<'){
            ll maxi=max(l,r), mini=min(l,r);
            ans+=maxi*(maxi+1)/2;
            ans+=(mini-1)*mini/2;
            l=r=0;
        }
        if(S[i]=='<') l++;
        if(S[i]=='>') r++;
        prev=S[i];
    }
    ll maxi=max(l,r), mini=min(l,r);
    ans+=maxi*(maxi+1)/2;
    ans+=(mini-1)*mini/2;

    cout<<ans<<endl;
}