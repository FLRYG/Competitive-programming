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

string S;
int T[200001];

int main(){
    cin>>S;

    rep(i,S.size()){
        int x=S[i]-'0';
        T[i+1]=T[i]+x;
    }

}