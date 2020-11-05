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

int N,R;
string S;
int cnt;
int tail;

int main(){
    cin>>N>>R>>S;
    rep(i,N) if(S[i]=='.'){
        cnt++;
        tail=i;
    }

    int ans=0;
    rep(i,tail-R+1){
        if(S[i]=='.'){
            ans++;
            for(int j=i;j<min(i+R,N);j++){
                if(S[j]=='.') cnt--;
                S[j]='o';
            }
        }
        if(cnt==0) break;
        ans++;
    }
    if(cnt>0) ans++;

    cout<<ans<<endl;
}