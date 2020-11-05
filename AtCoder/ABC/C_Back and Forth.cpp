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

int sx,sy,tx,ty;

int main(){
    cin>>sx>>sy>>tx>>ty;

    int h=ty-sy;
    int w=tx-sx;
    rep(i,h) cout<<'U';
    rep(i,w) cout<<'R';
    rep(i,h) cout<<'D';
    rep(i,w+1) cout<<'L';
    rep(i,h+1) cout<<'U';
    rep(i,w+1) cout<<'R';
    cout<<"DR";
    rep(i,h+1) cout<<'D';
    rep(i,w+1) cout<<'L';
    cout<<'U'<<endl;
}