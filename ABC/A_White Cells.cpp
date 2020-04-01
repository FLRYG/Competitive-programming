#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long ll;

int H,W;
int h,w;

int main(){
    cin>>H>>W>>h>>w;

    int ans=H*W-(W*h+w*H-h*w);

    cout<<ans<<endl;
}