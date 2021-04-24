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

int N,Q;
string S;

int main(){
    cin>>N>>S>>Q;

    bool flag=true;
    while(Q--){
        int T,A,B;
        cin>>T>>A>>B;
        A--, B--;
        if(T==1){
            if(flag) swap(S[A],S[B]);
            else{
                A=(A+N)%(2*N);
                B=(B+N)%(2*N);
                swap(S[A],S[B]);
            }
        }else{
            flag^=1;
        }
    }

    string ans=S;
    if(!flag){
        ans=S.substr(N,N)+S.substr(0,N);
    }

    cout<<ans<<endl;
    
    return 0;
}