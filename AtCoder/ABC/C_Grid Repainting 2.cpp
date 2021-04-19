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

int I[]={1,0,-1,0};
int J[]={0,1,0,-1};

int H,W;

int main(){
    cin>>H>>W;
    vector<vector<char>> s(H,vector<char>(W,'#'));
    rep(i,H) rep(j,W) cin>>s[i][j];

    rep(i,H) rep(j,W){
        if(s[i][j]=='.') continue;
        bool flag=true;
        rep(k,4){
            int x=i+I[k];
            int y=j+J[k];
            if(0<=x && x<H && 0<=y && y<W && s[x][y]=='#'){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
    
    return 0;
}