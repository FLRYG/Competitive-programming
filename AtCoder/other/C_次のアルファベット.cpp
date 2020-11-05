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

int main(){
    cin>>s>>K;

    int size=s.size();
    rep(i,size){
        int x=('z'-s[i]+1)%26;
        if(x<=K){
            s[i]='a';
            K-=x;
        }
    }
    K%=26;
    s[size-1]+=K;
    if(s[size-1]>'z') s[size]-=26;

    cout<<s<<endl;
}