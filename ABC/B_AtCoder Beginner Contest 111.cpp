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

int N;

int main(){
    cin>>N;

    int ans;
    repn(i,9){
        if(N<=i*111){
            ans=i*111;
            break;
        }
    }

    cout<<ans<<endl;
}