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

string s;

int main(){
    cin>>s;

    string t,u;
    rep(i,s.size()){
        if(s[i]!='x'){
            t+=s[i];
            u+=s[i];
        }
    }
    reverse(u.begin(),u.end());
    if(t!=u){
        cout<<-1<<endl;
        return 0;
    }

    int l=0, r=s.size()-1;
    int ans=0;
    while(l<r){
        if(s[l]==s[r]){
            l++;
            r--;
        }else{
            if(s[l]=='x'){
                while(s[l++]=='x') ans++;
                r--;
            }else if(s[r]=='x'){
                while(s[r--]=='x') ans++;
                l++;
            }
        }
    }

    cout<<ans<<endl;
}