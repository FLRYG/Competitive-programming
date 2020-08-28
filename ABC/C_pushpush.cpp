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
//typedef pair<int,int> P;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int n;
int a[200000];

int main(){
    cin>>n;
    rep(i,n) cin>>a[i];

    deque<int> q;
    rep(i,n){
        if(i%2==0) q.push_back(a[i]);
        else q.push_front(a[i]);
    }

    if(n%2==0) while(!q.empty()){
        cout<<q.front()<<' '; q.pop_front();
    }else while(!q.empty()){
        cout<<q.back()<<' '; q.pop_back();
    }
    cout<<endl;
}