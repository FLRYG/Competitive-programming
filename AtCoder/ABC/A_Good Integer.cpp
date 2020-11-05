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

int main(){
    cin>>s;

    if((s[0]==s[1] && s[1]==s[2]) || (s[1]==s[2] && s[2]==s[3])){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}