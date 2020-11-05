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

    int ans;
    if(N%2==0){
        ans=N;
    }else{
        ans=2*N;
    }

    cout<<ans<<endl;
}