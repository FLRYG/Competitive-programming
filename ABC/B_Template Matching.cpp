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

int N,M;
string A[50], B[50];

int main(){
    cin>>N>>M;
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];

    string ans="No";
    rep(i,N-M+1){
        rep(j,N-M+1){
            int flag=true;
            rep(k,M){
                rep(l,M){
                    if(A[k+i][l+j]!=B[k][l]){
                        flag=false;
                        goto a;
                    }
                }
            }
            a:;
            if(flag){
                ans="Yes";
                goto b;
            }
        }
    }
    b:;

    cout<<ans<<endl;
}