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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

string s;

int main(){
    cin>>s;

    int a,b,c;
    a=b=c=0;
    rep(i,s.size()){
        if(s[i]=='a') a++;
        if(s[i]=='b') b++;
        if(s[i]=='c') c++;
    }

    string ans="NO";
    if(abs(a-b)<=1 && abs(b-c)<=1 && abs(c-a)<=1) ans="YES";

    cout<<ans<<endl;
}