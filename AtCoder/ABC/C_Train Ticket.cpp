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

int A[4];

int main(){
    string s;
    cin>>s;
    rep(i,4) A[i]=s[i]-'0';

    string ans;
    rep(i,1<<3){
        int x=A[0];
        rep(j,3){
            if(i>>j&1) x+=A[j+1];
            else x-=A[j+1];
        }
        if(x==7){
            ans+=A[0]+'0';
            rep(j,3){
                if(i>>j&1) ans+='+';
                else ans+='-';
                ans+=A[j+1]+'0';
            }
            ans+="=7";
            break;
        }
    }

    cout<<ans<<endl;
    
    return 0;
}