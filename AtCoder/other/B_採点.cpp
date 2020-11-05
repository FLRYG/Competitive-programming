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
typedef pair<int,int> P;

int N,M;
int A[100001];

int main(){
    cin>>N>>M;
    rep(i,N){
        int a;
        cin>>a;
        A[a]++;
    }

    int ans=-1;
    int cnt=0;
    for(int i=0;i<=M;i++){
        if(A[i]>N/2){
            ans=i;
        }
    }
    if(ans==-1){
        cout<<'?'<<endl;
    }else{
        cout<<ans<<endl;
    }
}