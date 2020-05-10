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

int N,M;
map<int,int> m;

int main(){
    cin>>N>>M;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        m[a]++;
        m[b]++;
    }

    repr(e,m){
        if(e.second&1){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
}