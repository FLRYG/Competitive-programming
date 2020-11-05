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

string S[3];

int main(){
    rep(i,3) cin>>S[i];

    int idx[3]={0,0,0};
    int t=0;
    while(S[t].size()>idx[t]){
        if(S[t][idx[t]]=='a'){idx[t]++; t=0;}
        else if(S[t][idx[t]]=='b'){idx[t]++; t=1;}
        else if(S[t][idx[t]]=='c'){idx[t]++; t=2;}
    }

    string ans;
    if(t==0) ans='A';
    if(t==1) ans='B';
    if(t==2) ans='C';

    cout<<ans<<endl;
}