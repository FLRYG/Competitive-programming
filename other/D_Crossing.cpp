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

    int a;
    rep(i,N){
        int x=i*(i+1)/2;
        if(x==N){
            a=i;
            break;
        }
        if(N<x){
            cout<<"No"<<endl;
            return 0;
        }
    }

    vector<vector<int>> ans(a+1,vector<int>(0));
    int val=0;
    for(int n=a;n>=1;n--){
        repn(i,n){
            val++;
            ans[a-n].push_back(val);
            ans[a-n+i].push_back(val);
        }
    }

    cout<<"Yes\n"<<a<<endl;
    rep(i,a+1){
        cout<<ans[i].size()<<' ';
        rep(j,a){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}