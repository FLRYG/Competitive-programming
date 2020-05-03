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
using namespace std;
typedef long long ll;

struct q{
    int a,b,c,d;
    q(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){}
};

int N,M,Q;
q x[50];

int main(){
    cin>>N>>M>>Q;
    rep(i,Q){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        x[i]=q(a,b,c,d);
    }
}