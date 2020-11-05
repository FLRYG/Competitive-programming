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

int N;
int a[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>a[i];

    int res=0;
    rep(i,N){
        res^=a[i];
    }

    if(res==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}