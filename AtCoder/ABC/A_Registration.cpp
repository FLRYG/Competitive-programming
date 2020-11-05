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

string S,T;

int main(){
    cin>>S>>T;

    rep(i,S.size()){
        if(S[i]!=T[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
}