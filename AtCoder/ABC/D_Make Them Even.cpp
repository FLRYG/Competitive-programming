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
#define repr(X) for(auto& e:X)
using namespace std;
typedef long long ll;

struct P{
    int a,b,c,d;
    P(int a,int b,int c,int d):a(a),b(b),c(c),d(d){}
};

int H,W;
int a[500][500];

int main(){
    cin>>H>>W;
    rep(i,H) rep(j,W) cin>>a[i][j];
    
    vector<P> ans; 
    rep(i,H){
        rep(j,W){
            if(a[i][j]&1){
                if(j<W-1){
                    ans.push_back(P(i,j,i,j+1));
                    a[i][j]--;
                    a[i][j+1]++;
                }else if(i<H-1){
                    ans.push_back(P(i,j,i+1,j));
                    a[i][j]--;
                    a[i+1][j]++;
                }
            }
        }
    }

    int N=ans.size();
    cout<<N<<endl;
    repr(ans){
        cout<<e.a+1<<' '<<e.b+1<<' '<<e.c+1<<' '<<e.d+1<<endl;
    }
}