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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

string S;
ll K;

int main(){
    cin>>S>>K;
    
    if(K<=100){
        bool b=true;
        rep(i,K){
            if(S[i]!='1') b=false;
        }
        if(b){
            cout<<1<<endl;
            return 0;
        }
    }

    rep(i,S.size()){
        if(S[i]!='1'){
            cout<<S[i]<<endl;
            break;
        }
    }
}