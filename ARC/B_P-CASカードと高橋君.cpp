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
typedef pair<int,int> P;
//ll const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int x,y;
string W;
char c[28][28];

int main(){
    cin>>x>>y>>W;
    for(int i=10;i<=18;i++){
        for(int j=10;j<=18;j++){
            cin>>c[i][j];
        }
    }

    for(int i=1;i<=27;i++){
        for(int j=2;j<=9;j++){
            c[i][j]=c[i][18-j+2];
        }
    }
    for(int i=1;i<=27;i++){
        for(int j=19;j<=26;j++){
            c[i][j]=c[i][27-j+9];
        }
    }

    for(int j=1;j<=27;j++){
        for(int i=2;i<=9;i++){
            c[i][j]=c[18-i+2][j];
        }
    }
    for(int j=1;j<=27;j++){
        for(int i=19;i<=26;i++){
            c[i][j]=c[27-i+9][j];
        }
    }

    string ans;
    rep(i,4){
        ans+=c[9+y][9+x];
        rep(j,W.size()){
            if(W[j]=='R') x++;
            if(W[j]=='L') x--;
            if(W[j]=='U') y--;
            if(W[j]=='D') y++;
        }
    }

    cout<<ans<<endl;
}