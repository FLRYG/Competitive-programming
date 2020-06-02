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

string S,T;

bool chk(char a,char b){
    if(a==b || a=='?' || b=='?') return true;
    return false;
}

int main(){
    cin>>S>>T;

    if(S.size()<T.size()){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }
    int begin=-1;
    rep(i,S.size()-T.size()+1){
        bool flag=true;
        rep(j,T.size()){
            if(!chk(S[i+j],T[j])){
                flag&=false;
            }
        }
        if(flag) begin=i;
    }
    if(begin==-1){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }

    rep(i,S.size()){
        if(S[i]=='?') S[i]='a';
    }
    for(int i=begin;i<begin+T.size();i++){
        S[i]=T[i-begin];
    }

    cout<<S<<endl;
}