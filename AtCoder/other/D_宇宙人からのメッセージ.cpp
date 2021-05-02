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
#include <chrono>
#include <random>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
// typedef pair<int,int> P;
// typedef pair<int,P> IP;
// typedef pair<P,P> PP;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

string S;

int main(){
    cin>>S;

    deque<char> deq;
    bool flag=true;
    rep(i,S.size()){
        if(S[i]=='R') flag^=1;
        else if(flag) deq.push_back(S[i]);
        else deq.push_front(S[i]);
    }
    if(!flag) reverse(deq.begin(),deq.end());
    // repr(e,deq) cout<<e; cout<<endl;

    int N=deq.size();
    string T;
    rep(i,N){
        if(T.size()>0 && T[T.size()-1]==deq.front()){
            T.pop_back();
        }else{
            T.push_back(deq.front());
        }
        deq.pop_front();
    }

    cout<<T<<endl;
    
    return 0;
}