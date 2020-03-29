#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int N;
string S;

int ans[100000];

int main(){
    cin>>S;
    N=S.size();
    S+='R';

    int L=0,R=0;
    int index=0;
    char before='R';
    rep(i,N+1){
        if(before=='L' && S[i]=='R'){
            ans[index+R-1]=ceil(R/2.0)+L/2;
            ans[index+R]=ceil(L/2.0)+R/2;
            index+=L+R;
            L=0;
            R=0;
        }
        if(S[i]=='L') L++;
        if(S[i]=='R') R++;
        before=S[i];
    }

    rep(i,N){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}