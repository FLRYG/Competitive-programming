#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int N;
string S;

int ans[100000];

int main(){
    cin>>N>>S;

    int L=0,R=0;
    char before='L';
    rep(i,N){
        if(S[i]==before){
            if(S[i]=='L') L++;
            
        }
    }
}