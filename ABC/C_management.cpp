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
int A[200005];
int ans[200005];

int main(){
    cin>>N;
    for(int i=2;i<=N;i++) cin>>A[i];

    for(int i=2;i<=N;i++) ans[A[i]]++;

    repn(i,N) cout<<ans[i]<<endl;
}