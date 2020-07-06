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

int N;
string W[1000];

int main(){
    cin>>N;
    rep(i,N) cin>>W[i];

    vector<string> ans(N,"");
    rep(k,N){
        string s;
        rep(i,(int)W[k].size()){
            if(W[k][i]=='b' || W[k][i]=='B' || W[k][i]=='c' || W[k][i]=='C') s+="1";
            else if(W[k][i]=='d' || W[k][i]=='D' || W[k][i]=='w' || W[k][i]=='W') s+="2";
            else if(W[k][i]=='t' || W[k][i]=='T' || W[k][i]=='j' || W[k][i]=='J') s+="3";
            else if(W[k][i]=='f' || W[k][i]=='F' || W[k][i]=='q' || W[k][i]=='Q') s+="4";
            else if(W[k][i]=='l' || W[k][i]=='L' || W[k][i]=='v' || W[k][i]=='V') s+="5";
            else if(W[k][i]=='s' || W[k][i]=='S' || W[k][i]=='x' || W[k][i]=='X') s+="6";
            else if(W[k][i]=='p' || W[k][i]=='P' || W[k][i]=='m' || W[k][i]=='M') s+="7";
            else if(W[k][i]=='h' || W[k][i]=='H' || W[k][i]=='k' || W[k][i]=='K') s+="8";
            else if(W[k][i]=='n' || W[k][i]=='N' || W[k][i]=='g' || W[k][i]=='G') s+="9";
            else if(W[k][i]=='z' || W[k][i]=='Z' || W[k][i]=='r' || W[k][i]=='R') s+="0";
        }
        ans[k]=s;
    }

    bool e=false;
    rep(i,N){
        if(ans[i].size()>0){
            if(e) cout<<' ';
            cout<<ans[i];
            e=true;
        }
    }
    cout<<endl;
}