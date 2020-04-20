#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int H,W;
string a[105];

int main(){
    cin>>H>>W;
    rep(i,H) cin>>a[i];

    int r[105],c[105];
    rep(i,H){
        rep(j,W){
            if(a[i][j]=='#'){
                r[i]=1;
                c[j]=1;
            }
        }
    }

    rep(i,H){
        if(r[i]==1){
            rep(j,W){
                if(c[j]==1) cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}