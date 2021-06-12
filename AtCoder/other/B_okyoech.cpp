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

int N;

int main(){
    cin>>N;
    
    while(N--){
        string S;
        cin>>S;
        int x=-1, y=-1;
        rep(i,S.size()-3){
            if(S.substr(i,4)=="okyo"){
                x=i;
                break;
            }
        }
        rep(i,S.size()-2){
            if(S.substr(i,3)=="ech"){
                y=i;
            }
        }
        string ans="No";
        if(x!=-1 && y!=-1 && x<y) ans="Yes";
        cout<<ans<<endl;
    }
    
    return 0;
}