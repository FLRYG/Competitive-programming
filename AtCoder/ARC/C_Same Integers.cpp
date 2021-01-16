#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
double const PI=3.141592653589793;
int const INF=1001001001;
ll const LINF=1001001001001001001;
ll const MOD=1000000007;

int A[3];

int main(){
    rep(i,3) cin>>A[i];

    int ans=0;
    if(!((A[0]&1)==(A[1]&1) && (A[2]&1)==(A[1]&1))){  
        if((A[0]&1)==(A[2]&1)) swap(A[0],A[1]);  
        else if((A[0]&1)==(A[1]&1)) swap(A[0],A[2]);
        do{
            A[1]++;
            A[2]++;
            ans++;
        }while(A[0]>max(A[1],A[2]));
    }

    sort(A,A+3);
    ans+=(A[2]-A[1])/2;    
    ans+=(A[2]-A[0])/2; 

    cout<<ans<<endl;
    
    return 0;
}