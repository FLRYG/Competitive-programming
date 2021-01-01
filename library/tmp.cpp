#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
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
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N=20;

int main(){
    set<int> st{0,10,13,20};
    //rep(i,N) st.insert(i);

    ll score=0;
    for(auto i1=st.begin(),i2=++st.begin();i2!=st.end();i1++,i2++){
        cout<<*i1<<' '<<*i2<<endl;
        score+=(*i2-*i1)*(*i2-*i1-1)/2;
    }
    //repr(e,s) cout<<e<<endl;
    cout<<score<<endl;
    
    return 0;
}