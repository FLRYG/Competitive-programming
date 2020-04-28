#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

string S,T;

int main(){
    cin>>S>>T;

    rep(i,S.size()){
        char x=S[S.size()-1];
        S.pop_back();
        S=x+S;
        if(S==T){
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;
}