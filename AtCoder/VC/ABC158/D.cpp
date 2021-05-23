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
int Q;

int main(){
    cin>>S>>Q;

    deque<char> q;
    rep(i,S.size()) q.push_back(S[i]);

    bool f=true;
    while(Q--){
        int T;
        cin>>T;
        if(T==1) f=!f;
        else{
            int F;
            char C;
            cin>>F>>C;
            if(f){
                if(F==1) q.push_front(C);
                else q.push_back(C);
            }else{
                if(F==1) q.push_back(C);
                else q.push_front(C);
            }
        }
    }

    string ans;
    int l=q.size();
    if(f) rep(i,l) ans+=q.front(), q.pop_front();
    else rep(i,l) ans+=q.back(), q.pop_back();

    cout<<ans<<endl;
    
    return 0;
}