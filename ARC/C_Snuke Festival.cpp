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

int N;
priority_queue<int> A,B,C;
map<int,int> cntA, cntB;

int main(){
    cin >> N;
    rep(i,N){
        int x;
        cin>>x;
        A.push(x);
        cntA[x]++;
    }
    rep(i,N){
        int x;
        cin>>x;
        B.push(x);
        cntB[x]++;
    }
    rep(i,N){
        int x;
        cin>>x;
        C.push(x);
    }
    int sum=0;
    repr(e,cntA){
        e.second+=sum;
        sum=e.second;
    }
    sum=0;
    repr(e,cntB){
        e.second+=sum;
        sum=e.second;
    }

    int ans=0;
    while(!(A.empty() || B.empty() || C.empty())){
        int a=A.top();
        int b=B.top();
        int c=C.top();
        cout<<a<<' '<<b<<' '<<c<<endl;
        if(!(b<c)){
            B.pop();
        }else if(!(a<b)){
            A.pop();
        }else{
            ans+=cntA[a]*cntB[b];
            C.pop();
            cout<<ans<<endl;       
        }
    }
    cout<<ans<<endl;
}