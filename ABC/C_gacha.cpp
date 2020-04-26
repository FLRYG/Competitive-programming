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

int N;
map<string,int> m;

int main(){
    cin>>N;
    rep(i,N){
        string s;
        cin>>s;
        m[s]++;
    }

    int ans=m.size();
    cout<<ans<<endl;
}