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
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef long double ld;

string tostring(int x){
    string s;
    while(x>0){
        int i=x%2;
        s+=i+'0';
        x/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}

int N;
string X;
int memo[200001];

int main(){
    cin>>N>>X;

    int cnt=0;
    rep(i,N){
        if(X[i]=='1') cnt++;
    }

    rep(i,N){
        string s=X;
        int cn=cnt;
        if(s[i]=='0'){
            s[i]='1';
            cn++;
        }
        else{
            s[i]='0';
            cn--;
        }
        int ans=0;
        int y=0;
        do{
            string t=tostring(cn);
            rep(j,s.size()-t.size()+1){
                if(s[i]=='1'){
                    rep(k,t.size()){
                        if(t[k]=='1'){
                            if(s[j+k]=='1') s[j+k]='0';
                            else s[j+k]='1';
                        }
                    }
                }
            }
            string u;
            for(int i;1<<i<=cn;i++){
                u+=s[s.size()-i-1];
            }
            ans++;
        }while(y>0);
    }
}