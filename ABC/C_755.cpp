#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int powi(int x,int n){if(n==0)return 1;return x*powi(x,n-1);}

int N;
const int table[3]={3,5,7};

int def(int m){
    int res=0;
    rep(i,3){
        int k=10*m+table[i];
        
    }
}

int main(){
    cin>>N;
    
}