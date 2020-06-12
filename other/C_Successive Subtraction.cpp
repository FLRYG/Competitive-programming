#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
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
typedef pair<int,int> P;

int N;
int A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int plus=0, minus=0;
    rep(i,N){
        if(A[i]>=0) plus++;
        else minus++;
    }
    if(plus==0 || minus==0){
        if(plus==0){
            plus++;
            minus--;
        }else{
            plus--;
            minus++;
        }
    }
    
    sort(A,A+N);

    vector<P> x;
    int ans=A[minus-1];
    minus--;
    while(plus>1){
        x.push_back(P(ans,A[minus+plus]));
        ans-=A[minus+plus];
        plus--;
    }
    x.push_back(P(A[minus+plus],ans));
    ans=A[minus+plus]-ans;
    while(minus>0){
        x.push_back(P(ans,A[minus-1]));
        ans-=A[minus-1];
        minus--;
    }

    cout<<ans<<endl;
    repr(e,x){
        cout<<e.first<<' '<<e.second<<endl;
    }
}