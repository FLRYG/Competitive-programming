#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <unordered_map>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

string S,T;
int cnts[26],cntt[26];

int main(){
    cin>>S>>T;

    rep(i,S.size()){
        cnts[S[i]-'a']++;
        cntt[T[i]-'a']++;
    }

    rep() 
}