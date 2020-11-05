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

int K,X;

int main(){
    cin>>K>>X;

    for(int i=X-K+1;i<=X+K-1;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}