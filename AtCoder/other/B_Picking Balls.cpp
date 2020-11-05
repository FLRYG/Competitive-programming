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
typedef long double ld;
typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;
vector<int> R;
vector<int> B;

int main(){
    cin>>N;
    rep(i,N){
        int x;
        char c;
        cin>>x>>c;
        if(c=='R') R.push_back(x);
        if(c=='B') B.push_back(x);
    }

    sort(R.begin(),R.end());
    sort(B.begin(),B.end());

    repr(e,R) cout<<e<<endl;
    repr(e,B) cout<<e<<endl;
}