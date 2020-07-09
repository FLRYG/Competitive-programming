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

string s;
int cnt[26];

int main(){
    cin>>s;

    int ans=1001001001;
    rep(i,26){
        char c='a'+i;
        string t=s;
        int cnt=0;
        while(true){
            bool b=true;
            rep(j,t.size()){
                b&=t[j]==c;
            }
            if(b) break;

            string res;
            rep(j,t.size()-1){
                if(t[j]==c || t[j+1]==c){
                    res+=c;
                }else{
                    res+=t[j];
                }
            }
            cnt++;
            t=res;
        }
        ans=min(ans,cnt);
    }

    cout<<ans<<endl;
}