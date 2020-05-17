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

int N;

int main(){
    cin>>N;

    int x=N%10;
    string ans;
    if(x==3){
        ans="bon";
    }else if(x==0 || x==1 || x==6 || x==8){
        ans="pon";
    }else{
        ans="hon";
    }

    cout<<ans<<endl;
}