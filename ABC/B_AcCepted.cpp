#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

string S;

int main(){
    cin>>S;

    string ans="AC";
    if(S[0]!='A') ans="WA";
    int cnt=0;
    for(int i=2;i<S.size()-1;i++){
        if(S[i]=='C') cnt++;
    }
    if(cnt!=1) ans="WA";
    rep(i,S.size()){
        if(!(S[i]=='A' || S[i]=='C')){
            if(!('a'<=S[i] && S[i]<='z')) ans="WA";
        }
    }

    cout<<ans<<endl;
}