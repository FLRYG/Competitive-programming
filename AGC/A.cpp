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
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int T;
string a="atcoder";

int main(){
    cin>>T;

    vector<int> ans(T,0);
    rep(k,T){
        string s;
        cin>>s;

        if(a<s) continue;

        vector<int> cnt(26);
        rep(i,s.size()) cnt[s[i]-'a']++;

        if(cnt[0]==s.size()){
            ans[k]=-1;
            continue;
        }
        
        int res=INF;
        rep(i,s.size()){
            int cnt=max(0,i-6);
            //cout<<s[i]<<endl;
            for(int j=min(i,6);j>=0;j--){
                //cout<<' '<<a[j]<<endl;
                if(s[i]>a[j]){
                    //cout<<' '<<cnt<<endl;
                    res=min(res,cnt);
                    break;
                }
                else cnt++;
            }
        }
        ans[k]=res;
    }

    rep(i,T) cout<<ans[i]<<endl;
}