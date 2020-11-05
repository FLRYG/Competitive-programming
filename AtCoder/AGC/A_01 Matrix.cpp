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
using namespace std;
typedef long long ll;

int H,W,A,B;
int ans[1000][1000];

int main(){
    cin>>H>>W>>A>>B;

    for(int i=0;i<B;i++){
        for(int j=A;j<W;j++){
            ans[i][j]=1;
        }
    }
    for(int i=B;i<H;i++){
        for(int j=0;j<A;j++){
            ans[i][j]=1;
        }
    }

    rep(i,H){
        rep(j,W){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}