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
char c[20];

int main(){
    cin>>s;
    if(s.size()==1){
        if(s=="a"){
            cout<<"NO"<<endl;
            return 0;
        }
        s[0]--;
        s+='a';
        cout<<s<<endl;
        return 0;
    }
    if(s.size()==2 && s[s.size()-1]-s[0]==1){
        s[s.size()-1]--;
        s+='a';
        cout<<s<<endl;
        return 0;
    }
    sort(s.begin(),s.end(),greater<>());
    s[0]--;
    s[s.size()-1]++;
    if(s[0]<'a'){
        s=s.size()+'a'-1;
    }else if(s[s.size()-1]>'z'){
        s[s.size()-1]--;
        s+='a';
    }

    if(s.size()<=20){
        cout<<s<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}