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
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int N;

int main(){
    cin>>N;
    vector<int> ans(6,0);
    rep(i,N){
        double T,t;
        cin>>T>>t;
        if(T>=35){
            ans[0]++;
        }else if(T>=30){
            ans[1]++;
        }else if(T>=25){
            ans[2]++;
        }
        if(t>=25){
            ans[3]++;
        }
        if(t<0 && T>=0){
            ans[4]++;
        }
        if(T<0){
            ans[5]++;
        }
    }

    rep(i,5) cout<<ans[i]<<' ';
    cout<<ans[5]<<endl;
}