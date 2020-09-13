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

int H,W,N;
int sr,sc;
string S,T;
int cnt[2][4][200001];

int main(){
    cin>>H>>W>>N>>sr>>sc>>S>>T;
    map<char,int> m;
    m['L']=0;
    m['R']=1;
    m['U']=2;
    m['D']=3;

    repn(i,N){
        cnt[0][m[S[i-1]]][i]++;
        cnt[1][m[T[i-1]]][i]++;
    }
    rep(i,2){
        rep(j,4){
            repn(k,N){
                cnt[i][j][k]+=cnt[i][j][k-1];
            }
        }
    }

    int x=sr, y=sc;
    rep(i,N){
        if(S[i]=='L') x--;
        if(S[i]=='U') y--;
        if(x<1 || y<1){
            
        }
    }

    cout<<"YES"<<endl;
}