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
string S,T;

int main(){
    cin>>N>>S>>T;

    vector<int> ids(0), idt(0);
    ids.reserve(N);
    idt.reserve(N);
    rep(i,N) if(S[i]=='0') ids.push_back(i);
    rep(i,N) if(T[i]=='0') idt.push_back(i);

    if(ids.size()!=idt.size()){
        cout<<-1<<endl;
        return 0;
    }

    int ans=0;
    rep(i,ids.size()) ans+=ids[i]!=idt[i];

    cout<<ans<<endl;
    
    return 0;
}