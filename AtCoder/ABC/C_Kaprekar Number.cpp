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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=2147483647;
ll const LINF=9223372036854775807;
ll const MOD=1000000007;

int N,K;

int main(){
    cin>>N>>K;

    vector<int> v;
    rep(i,K){
        v.clear();
        while(N>0){
            v.push_back(N%10);
            N/=10;
        }
        sort(v.begin(),v.end());
        int g1=0, g2=0;
        rep(i,v.size()){
            g1*=10;
            g1+=v[v.size()-1-i];
            g2*=10;
            g2+=v[i];
        }
        N=g1-g2;
    }

    cout<<N<<endl;
    
    return 0;
}