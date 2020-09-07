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

int N;
string W[100];

int main(){
    cin>>N;
    rep(i,N) cin>>W[i];

    rep(i,N){
        bool out=false;
        if(i>0 && W[i][0]!=W[i-1][W[i-1].size()-1]) out=true;
        rep(j,i){
            if(W[i]==W[j]) out=true;
        }
        if(out){
            if(i&1){
                cout<<"WIN"<<endl;
                return 0;
            }else{
                cout<<"LOSE"<<endl;
                return 0;
            }
        }
    }

    cout<<"DRAW"<<endl;
}