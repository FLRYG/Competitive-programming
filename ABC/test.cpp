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

const char* c="ACGT";

int main(){
    string ans="";
    rep(i,4){
        ans+=c[i];
        rep(j,4){
            ans+=c[j];
            rep(k,4){
                ans+=c[k];
                cout<<ans<<endl;
                ans.pop_back();
            }
            ans.pop_back();
        }
        ans.pop_back();
    }
}