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

int A,B,C;

int main(){
    cin>>A>>B>>C;

    int ans=max(A,max(B,C))*10+A+B+C-max(A,max(B,C));

    cout<<ans<<endl;
}