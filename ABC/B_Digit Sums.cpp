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

int main(){
    cin>>N;

    int n=N;
    int sum=0;
    rep(i,log10(N)+1){
        sum+=n%10;
        n/=10;
    }

    if(N%sum==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}