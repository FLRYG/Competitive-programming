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

ll N;
ll A[200001];
ll sum[200001];

int main(){
    cin>>N;
    repn(i,N) cin>>A[i];

    repn(i,N-1){
        sum[i]=sum[i-1]+A[i];
    }
}