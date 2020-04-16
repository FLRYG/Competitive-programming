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

int N;
int A,B,C;
int L[8];

int main(){
    cin>>N>>A>>B>>C;
    rep(i,N) cin>>L[i];

    int ans=1001001001;
    for(int i=0;i<(1<<(2*N));i++){
        int res=0;
        int abc[3]={0,0,0};
        rep(j,N){
            int t=(i>>(2*j))%4;
            if(t!=3){
                abc[t]+=L[j];
                if(abc[t]!=L[j]) res+=10;
            }
        }
        
        if(abc[0]!=0 && abc[1]!=0 && abc[2]!=0){
            res+=abs(A-abc[0]);
            res+=abs(B-abc[1]);
            res+=abs(C-abc[2]);
            ans=min(ans,res);
        }
    }

    cout<<ans<<endl;
}