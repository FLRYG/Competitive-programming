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

int N;
string S;

int main(){
    cin>>N>>S;

    int ans=0;
    rep(num,1000){
        char a='0'+(num/100);
        char b='0'+num/10%10;
        char c='0'+num%10;
        int cnt=0;
        rep(i,N){
            if(cnt==0 && S[i]==a) cnt++;
            else if(cnt==1&& S[i]==b) cnt++;
            else if(cnt==2&& S[i]==c) cnt++;
            else if(cnt==3) break;
        }
        if(cnt==3) ans++;
    }

    cout<<ans<<endl;
}