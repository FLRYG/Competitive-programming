#include <iostream>
#include <stdio.h>
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

int N;

int pow10(int n){
    int res=1;
    rep(i,n) res*=10;
    return res;
}

inline int digit(int n){
    return log10(n)+1;
}

int main(){
    cin>>N;

    int res[10][10];
    rep(i,100) res[i/10][i%10]=0;
    repn(n,N){
        int bbegin=n/pow10(digit(n)-1);
        int bend=n%10;
        res[bbegin][bend]++;
    }

    int ans=0;
    repn(abegin,9){
        repn(aend,9){
            ans+=res[abegin][aend]*res[aend][abegin];
        }
    }

    cout<<ans<<endl;
}