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
#include <bitset>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

string S;

int main(){
    cin>>S;
    int N=S.size();

    ll ans=0;
    stack<char> stk1;
    stack<int> stk2;
    rep(i,N-2){
        if(!stk1.empty() && S[i]==stk1.top()){
            cout<<i<<" pop"<<S[i]<<endl;
            ans+=i-stk2.top()-2;
            stk1.pop();
            stk2.pop();
        }
        if(S[i]==S[i+1]){
            cout<<i<<" push"<<S[i]<<endl;
            stk1.push(S[i]);
            stk2.push(i);
            i++;
        }
    }
    while(!stk1.empty()){
        cout<<N<<" pop"<<stk1.top()<<endl;
        ans+=N-stk2.top()-2;
        stk1.pop();
        stk2.pop();
    }

    cout<<ans<<endl;
    
    return 0;
}