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

string N;

int main(){
    cin>>N;

    int cnt=0;
    rep(i,N.size()){
        if(N[N.size()-1-i]=='0') cnt++;
        else break;
    }

    rep(i,cnt) N.insert(0,"0");

    rep(i,(N.size()+1)/2){
        if(N[i]!=N[N.size()-1-i]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
    
    return 0;
}