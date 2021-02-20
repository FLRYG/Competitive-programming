#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

string S;

int main(){
    cin>>S;

    rep(i,S.size()){
        if(i&1){
            if(!('A'<=S[i] && S[i]<='Z')){
                cout<<"No"<<endl;
                return 0;
            }
        }else{
            if(!('a'<=S[i] && S[i]<='z')){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }

    cout<<"Yes"<<endl;
    
    return 0;
}