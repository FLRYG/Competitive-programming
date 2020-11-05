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
typedef pair<int,int> P;

string S;

int main(){
    cin>>S;

    string T;
    rep(i,S.size()){
        if(i!=S.size()-1 && S[i]=='B' && S[i+1]=='C'){
            T+='X';
            i++;
        }else{
            T+=S[i];
        }
    }
    
    ll ans=0;
    ll cnt=0;
    for(int i=T.size()-1;i>=0;i--){
        if(T[i]=='X'){
            cnt++;
        }else if(T[i]=='A'){
            ans+=cnt;
        }else{
            cnt=0;
        }
    }

    cout<<ans<<endl;
}