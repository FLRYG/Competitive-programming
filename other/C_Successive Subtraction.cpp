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

int N;
int A[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>A[i];

    int plus=0, minus=0;// zero=0;
    int ans=0;
    rep(i,N){
        ans+=A[i];
        if(A[i]>=0) plus++;
        else minus++;
    }
    if(plus==0 || minus==0){
        ans-=2;
        cout<<ans<<endl;
        cout<<A[N-1]<<' '<<A[0]<<endl;
        if(plus==0){
            A[0]=A[N-1]-A[0];
            plus++;
            minus--;
            N--;
        }else{
            A[0]=A[0]-A[N-1];
            plus--;
            minus++;
            N--;
        }
    }else{
        cout<<ans<<endl;
    }
    
    sort(A,A+N);

    int a=A[minus-1];
    minus--;
    while(plus>1){
        cout<<a<<' '<<A[minus+plus]<<endl;
        a-=A[minus+plus];
        plus--;
    }
    cout<<a<<' '<<A[minus+plus]<<endl;
    a=A[plus-1]-a;
    while(minus>0){
        cout<<a<<A[minus-1]<<endl;
        a-=A[minus-1];
        minus--;
    }
}