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
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

string n;

int main(){
    cin>>n;

    rep(i,3){
        if(n[i]=='1') n[i]='9';
        else n[i]='1';
    }

    cout<<n<<endl;
}