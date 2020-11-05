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

int N,K;
string S;

int main(){
    cin>>N>>K>>S;

    bool s1Left=S[0]=='L'?1:0;
    bool snRight=S[N-1]=='R'?1:0;

    char t=S[0];
    int rl=0;
    int ans=0;
    for(int i=1;i<N;i++){
        if(t==S[i]){
            ans++;
        }else if(t=='R' && S[i]=='L'){
            rl++;
        }
        t=S[i];
    }

    ans+=2*min(rl,K);
    if(K>rl){
        if(s1Left && snRight){
            ans=min(ans+1,N-1);
        }else{
            ans=min(ans+2,N-1);
        }
    }

    cout<<ans<<endl;
}