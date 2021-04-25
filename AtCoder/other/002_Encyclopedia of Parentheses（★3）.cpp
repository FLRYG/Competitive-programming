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

    vector<string> ans(0);
    repn(i,(1<<N)-1){
        int cnt=0;
        bool flag=true;
        rep(j,N){
            if(i>>j&1) cnt++;
            else cnt--;
            if(cnt<0) break;
        }
        if(cnt!=0) continue;
        string s;
        rep(j,N){
            if(i>>j&1) s+='(';
            else s+=')';
        }
        ans.push_back(s);
    }
    sort(ans.begin(),ans.end());

    repr(e,ans) cout<<e<<endl;
    
    return 0;
}