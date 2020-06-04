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

int N, M;
string name, kit;
int cntname[26], cntkit[26];

int main(){
    cin>>N>>M>>name>>kit;

    rep(i,N) cntname[name[i]-'A']++;
    rep(i,M) cntkit[kit[i]-'A']++;

    int ans=0;
    rep(i,26){
        if(cntkit[i]==0){
            if(cntname[i]>0){
                ans=-1;
                break;
            }
            continue;
        }
        int x=(cntname[i]-1)/cntkit[i]+1;
        ans=max(ans,x);
    }

    cout<<ans<<endl;
}