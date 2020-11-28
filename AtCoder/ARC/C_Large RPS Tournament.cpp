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

int n,k;
string S;

string f(string s, int m){
    //cout<<s<<' '<<m<<endl;
    string res;
    if(m==k || s.size()==1){
        res+=s[0];
        return res;
    }
    if(s.size()%2==1) s+=s;
    //cout<<s<<' '<<m<<' '<<s.size()<<endl;
    rep(i,s.size()/2){
        if(s[2*i]=='R' && s[2*i+1]=='S') res+='R';
        if(s[2*i]=='P' && s[2*i+1]=='R') res+='P';
        if(s[2*i]=='S' && s[2*i+1]=='P') res+='S';
        if(s[2*i]=='S' && s[2*i+1]=='R') res+='R';
        if(s[2*i]=='R' && s[2*i+1]=='P') res+='P';
        if(s[2*i]=='P' && s[2*i+1]=='S') res+='S';
        if(s[2*i]==s[2*i+1]) res+=s[2*i];
    }
    return f(res,m+1);
}

int main(){
    cin>>n>>k>>S;

    cout<<f(S,0)<<endl;
    
    return 0;
}