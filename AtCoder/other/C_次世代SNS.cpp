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
 
int main(){
    getline(cin,S);
 
    map<string,int> m;
    bool a=false;
    string t;
    rep(i,S.size()){
        if(S[i]=='@') a=true;
        if(a){
            if('a'<=S[i] && S[i]<='z') t+=S[i];
            else if(S[i]=='@'){
                if(t.size()) m[t]=1;
                t.clear();
            }
            else if(S[i]==' '){
                if(t.size()) m[t]=1;
                a=false;
                t.clear();
            }
        }
    }
    if(a){
        if(t.size()) m[t]=1;
        a=false;
        t.clear();
    }
 
    repr(e,m){
        cout<<e.first<<endl;
    }
}