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
int N;
string t[50];

int main(){
    getline(cin,s);
    cin>>N;
    rep(i,N) cin>>t[i];
    s+=' ';

    int l=0;
    string u;
    rep(i,s.size()){
        if(s[i]!=' '){
            u+=s[i];
        }else{
            rep(j,N){
                if(t[j].size()!=u.size()) continue;
                //cout<<t[j]<<' '<<u<<endl;
                bool flag=true;
                rep(k,t[j].size()){
                    if(t[j][k]==u[k] || t[j][k]=='*') continue;
                    flag=false;
                    break;
                }
                if(flag){
                    for(int k=i-u.size();k<i;k++){
                        s[k]='*';
                    }
                    break;
                }
            }
            u.clear();
        }
    }

    cout<<s<<endl;
}