#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
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
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

int H,W;

int main(){
    cin>>H>>W;

    if(H==1){
        string ans;
        rep(i,W/7) ans+="5555522";
        if(W%7==2) ans.insert(0,"22");
        else if(W%7==5) ans+="55555";
        else if(W%7!=0){
            cout<<"No"<<endl;
            return 0;
        }
        cout<<"Yes"<<endl;
        cout<<ans<<endl;
    }else if(H==2){
        string ans[2];
        rep(i,W/7){
            ans[0]+="5552552";
            ans[1]+="5525552";
        }
        if(W%7==1){
            ans[0].insert(0,"2");
            ans[1].insert(0,"2");
        }else if(W%7==6){
            ans[0]+="555255";
            ans[1]+="552555";
        }else if(W%7!=0){
            cout<<"No"<<endl;
            return 0;
        }
        cout<<"Yes"<<endl;
        cout<<ans[0]<<endl;
        cout<<ans[1]<<endl;
    }else if(W==1){
        string ans;
        rep(i,H/7) ans+="5555522";
        if(H%7==2) ans.insert(0,"22");
        else if(H%7==5) ans+="55555";
        else if(H%7!=0){
            cout<<"No"<<endl;
            return 0;
        }
        cout<<"Yes"<<endl;
        rep(i,ans.size()) cout<<ans[i]<<endl;
    }else if(W==2){
        string ans[2];
        rep(i,H/7){
            ans[0]+="5552552";
            ans[1]+="5525552";
        }
        if(H%7==1){
            ans[0].insert(0,"2");
            ans[1].insert(0,"2");
        }else if(H%7==6){
            ans[0]+="555255";
            ans[1]+="552555";
        }else if(H%7!=0){
            cout<<"No"<<endl;
            return 0;
        }
        cout<<"Yes"<<endl;
        rep(i,ans[0].size()) cout<<ans[0][i]<<ans[1][i]<<endl;
    }else if(H==3 && W==3){
        string ans;
        ans+="252\n";
        ans+="252\n";
        ans+="555\n";
        cout<<"Yes"<<endl;
        cout<<ans;
    }else{
        cout<<"No"<<endl;
    }
    
    return 0;
}