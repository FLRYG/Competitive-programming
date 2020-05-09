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

int H,W;
char S[102][102];
char T[102][102];
char ans[102][102];

int main(){
    cin>>H>>W;
    repn(i,H) repn(j,W) cin>>S[i][j];
    rep(i,H+2){
        S[i][0]='#';
        S[i][W+1]='#';
    }
    rep(i,W+2){
        S[0][i]='#';
        S[H+1][i]='#';
    }
    rep(i,H+2) rep(j,W+2){
        T[i][j]='.';
        ans[i][j]='.';
    }

    repn(i,H){
        repn(j,W){
            bool flag=true;
            for(int k=i-1;k<=i+1;k++){
                for(int l=j-1;l<=j+1;l++){
                    if(S[k][l]=='.') flag=false;
                }
            }
            if(flag){
                ans[i][j]='#';
                for(int k=i-1;k<=i+1;k++){
                    for(int l=j-1;l<=j+1;l++){
                        T[k][l]='#';
                    }
                }
            }
        }
    }

    bool b=true;
    repn(i,H){
        repn(j,W){
            if(S[i][j]!=T[i][j]) b=false;
        }
    }

    if(b){
        cout<<"possible"<<endl;
        repn(i,H){
            repn(j,W){
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }else{
        cout<<"impossible"<<endl;
    }
}