#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int S;

int main(){
    cin>>S;

    int s1=S/100;
    int s2=S%100;

    string ans;
    if(1<=s1 && s1<=12 && 1<=s2 && s2<=12){
        ans="AMBIGUOUS";
    }else if(1<=s1 && s1<=12){
        ans="MMYY";
    }else if(1<=s2 && s2<=12){
        ans="YYMM";
    }else{
        ans="NA";
    }

    cout<<ans<<endl;
}