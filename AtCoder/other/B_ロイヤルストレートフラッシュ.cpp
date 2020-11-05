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

string s;
map<char,int> cnt;

int main(){
    cin>>s;

    int sum=s.size();
    char key;
    rep(i,s.size()){
        if(s[i+1]=='1' || s[i+1]=='J' || s[i+1]=='Q' || s[i+1]=='K' || s[i+1]=='A'){
            cnt[s[i]]++;
            if(cnt[s[i]]>=5){
                key=s[i];
                sum=i+2;
                break;
            }
        }
        if(s[i+1]=='1') i+=2;
        else i++;
    }

    string ans;
    rep(i,sum){
        string c;
        c+=s[i];
        c+=s[i+1];
        if(s[i+1]=='1') c+=s[i+2];
        if(c[0]!=key) ans+=c;
        else if('2'<=c[1] && c[1]<='9') ans+=c;
        if(s[i+1]=='1') i++;
        i++;
    }
    if(ans=="") ans+='0';

    cout<<ans<<endl;
}