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

int N;
string S;
ll R=0,G=0,B=0;

int main(){
    cin>>N>>S;

    rep(i,N){
        if(S[i]=='R') R++;
        else if(S[i]=='G') G++;
        else B++;
    }

    ll ans=R*G*B;
    rep(i,N){
        repn(j,N){
            if(i+j*2>=N) break;
            if(S[i]!=S[i+j] && S[i+j]!=S[i+j*2] && S[i+j*2]!=S[i]){
                ans--;
            }
        }
    }

    cout<<ans<<endl;
}