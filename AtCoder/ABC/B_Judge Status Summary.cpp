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

int N;
string S[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>S[i];

    map<string,int> m;
    rep(i,N) m[S[i]]++;

    cout<<"AC x "<<m["AC"]<<endl;
    cout<<"WA x "<<m["WA"]<<endl;
    cout<<"TLE x "<<m["TLE"]<<endl;
    cout<<"RE x "<<m["RE"]<<endl;
}