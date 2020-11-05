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

string s,t;

int main(){
    cin>>s>>t;

    int ans=-1;
    int cnt=0;
    rep(i,s.size()){
        if(s==t){
            ans=cnt;
            break;
        }
        string c; c+=s[s.size()-1];
        s.insert(0,c);
        s.pop_back();
        cnt++;
    }

    cout<<ans<<endl;
}