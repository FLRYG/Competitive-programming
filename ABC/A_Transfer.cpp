#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int A,B,C;

int main(){
    cin>>A>>B>>C;
    
    cout<<max(0,B+C-A)<<endl;
}