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
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int main(){
    int N;
    cin>>N;
    map<int,int> D;
    rep(i,N){
        int d;
        cin>>d;
        D[d]++;
    }
    int M;
    cin>>M;
    map<int,int> T;
    rep(i,M){
        int t;
        cin>>t;
        T[t]++;
    }

    string ans="YES";
    repr(e,T){
        if(D[e.first]<e.second){
            ans="NO";
            break;
        }
    }

    cout<<ans<<endl;
}