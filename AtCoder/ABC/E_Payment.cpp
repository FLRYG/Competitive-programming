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
    reverse(N.begin(),N.end());

    int flag=0;
    rep(i,N.size()){
        if(flag){
            int x=N[i]-'0'+1;
            if(x!=10) flag=0;
            N[i]=x%10+'0';
        }
        int x=N[i]-'0';
        if(x>5){
            N[i]=(10-x)+'0';
            flag++;
        }
    }
    if(flag) N.push_back('0'+flag);
    reverse(N.begin(),N.end());
    cout<<N<<endl;

    int ans=0;
    rep(i,N.size()) ans+=N[i]-'0';

    cout<<ans<<endl;
    
    return 0;
}