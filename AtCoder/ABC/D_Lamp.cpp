#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int H,W;
char S[2002][2002];
int L[2002][2002];
int R[2002][2002];
int U[2002][2002];
int D[2002][2002];

int main(){
    cin>>H>>W;
    repn(i,H) repn(j,W) cin>>S[i][j];

    repn(i,H){
        repn(j,W){
            if(S[i][j]=='#') L[i][j]=0;
            else L[i][j]=L[i][j-1]+1;

            if(S[i][W-j+1]=='#') R[i][W-j+1]=0;
            else R[i][W-j+1]=R[i][W-j+2]+1;

            if(S[i][j]=='#') U[i][j]=0;
            else U[i][j]=U[i-1][j]+1;

            if(S[H-i+1][j]=='#') D[H-i+1][j]=0;
            else D[H-i+1][j]=D[H-i+2][j]+1;
        }
    }

    int ans=0;
    repn(i,H){
        repn(j,W){
            ans=max(ans,L[i][j]+R[i][j]+U[i][j]+D[i][j]-3); 
        }
    }

    cout<<ans<<endl;
}