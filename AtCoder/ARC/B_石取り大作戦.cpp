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
int A,B;

int main(){
    cin>>N>>A>>B;

    string ans;
    if(N<=A){
        ans="Takahashi";
    }else if(A==B){
        if(N%(B+1)!=0){
            ans="Takahashi";
        }else{
            ans="Aoki";
        }
    }else{
        if(A>B){
            ans="Takahashi";
        }else{
            ans="Aoki";
        }
    }

    cout<<ans<<endl;
}