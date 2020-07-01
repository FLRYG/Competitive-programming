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
typedef long double ld;

int main(){
    int N;
    cin>>N;
    vector<int> b(N);
    rep(i,N) cin>>b[i];

    vector<int> ans(N);
    rep(i,N){
        int idx=-1;
        rep(j,N-i){
            if(b[j]==j+1){
                idx=j;
            }
        }
        if(idx==-1){
            cout<<-1<<endl;
            return 0;
        }else{
            ans[N-i-1]=idx+1;
            b.erase(b.begin()+idx);
        }
    }

    rep(i,N){
        cout<<ans[i]<<endl;
    }
}