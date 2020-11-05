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
    s+='}';

    string ans;
    int cnt=1;
    char bef=s[0];
    repn(i,s.size()-1){
        if(bef==s[i]) cnt++;
        else{
            ans+=bef;
            string t;
            while(cnt>0){
                t+=(cnt%10)+'0';
                cnt/=10;
            }
            reverse(t.begin(),t.end());
            ans+=t;
            cnt=1;
            bef=s[i];
        }
    }

    cout<<ans<<endl;
}