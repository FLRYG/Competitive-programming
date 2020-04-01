#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,Q;
string S;
int l[100000];
int r[100000];
int L[100001];

int main(){
    cin>>N>>Q>>S;
    rep(i,Q) cin>>l[i]>>r[i];

    int sumL=0;
    rep(i,N-1){
        if(S[i]=='A' && S[i+1]=='C'){
            sumL++;
        }
        L[i+2]=sumL;
    }

    /*for(int i=0;i<=N;i++) cout<<L[i]<<' ';
    cout<<endl;*/

    rep(i,Q){
        int ans=L[r[i]]-L[l[i]-1];
        if(L[l[i]-1]!=L[l[i]]) ans--;
        cout<<ans<<endl;
    }
}