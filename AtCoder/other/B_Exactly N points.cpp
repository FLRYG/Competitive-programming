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
//int const INF=1001001001;
ll const INF=1001001001001001001;
ll const MOD=1000000007;

ll N;

int main(){
    cin>>N;

    ll num=0;
    repn(i,N){
        if(N<=i*(i+1)/2){
            num=i;
            break;
        }
    }
    
    repn(i,num){
        if(i==num*(num+1)/2-N) continue;
        cout<<i<<endl;
    }
}