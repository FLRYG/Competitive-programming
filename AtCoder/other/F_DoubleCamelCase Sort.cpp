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
    int N=S.size();

    vector<string> memo;
    int l=0, r=0;
    while(l<N){
        r=l+1;
        while(r<N && 'a'<=S[r]) r++;
        r++;
        // cout<<S.substr(l,r-l)<<endl;
        memo.push_back(S.substr(l,r-l));
        l=r;
    }

    sort(memo.begin(),memo.end(),[](string x, string y){
        *(x.begin())+=-'A'+'a';
        *(x.end()-1)+=-'A'+'a';
        *(y.begin())+=-'A'+'a';
        *(y.end()-1)+=-'A'+'a';
        return x<y;
    });

    repr(e,memo) cout<<e; cout<<endl;
    
    return 0;
}