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

    rep(i,s.size()-1){
        if(s[i]==s[i+1]){
            cout<<i+1<<' '<<i+2<<endl;
            return 0;
        }
    }
    rep(i,s.size()-2){
        if(s[i]==s[i+2]){
            cout<<i+1<<' '<<i+3<<endl;
            return 0;
        }
    }

    cout<<-1<<' '<<-1<<endl;
}