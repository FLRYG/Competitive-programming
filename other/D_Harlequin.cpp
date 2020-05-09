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

int main(){
    int n;
    int a[100000];
    cin>>n;
    rep(i,n) cin>>a[i];

    int ans=0;
    rep(i,n) ans|=(a[i]&1);

    if(ans){
        cout<<"first"<<endl;
    }else{
        cout<<"second"<<endl;
    }
}