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
int a[100001];
bool b[100001];

int main(){
    cin>>N;
    repn(i,N) cin>>a[i];

    int ans=0;
    int i=1;
    while(true){
        if(i==2){
            cout<<ans<<endl;
            return 0;
        }
        if(b[i]){
            cout<<-1<<endl;
            return 0;
        }
        b[i]=true;
        ans++;
        i=a[i];
    }
}