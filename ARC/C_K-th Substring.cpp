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

string s;
int K;
vector<string> ans;

int main(){
    cin>>s>>K;
    string z="{";
    rep(i,5) ans.push_back(z);

    rep(i,s.size()){
        string t;
        int cnt=0;
        bool flag=true;
        while(flag && i+cnt<s.size()){
            char c=s[i+cnt++];
            t+=c;
            rep(j,5){
                if(t==ans[j]){
                    goto a;
                }
                if(t<ans[j]){
                    ans.pop_back();
                    ans.insert(ans.begin()+j,t);
                    goto a;
                }
            }
            flag=false;
            a:;
        }
    }
    
    cout<<ans[K-1]<<endl;
}