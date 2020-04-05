#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

string S;
int length;
int dp[100000][13];

int main(){
    cin>>S;
    length=S.size();

    for(int i=0;i<length;i++){
        int x;
        if(S[length-i-1]=='?') x=-1;
        else S[length-i-1]-'0';

        

    }
}