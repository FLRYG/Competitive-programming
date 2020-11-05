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
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int N,X,Y;
int ans[2000];

int main(){
    cin>>N>>X>>Y;

    for(int i=1;i<=N-1;i++){
        for(int j=i+1;j<=N;j++){
            int k=min(abs(i-j),abs(i-X)+1+abs(j-Y));
            ans[k]++;
        }
    }

    repn(i,N-1) cout<<ans[i]<<endl;
}