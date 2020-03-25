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

int N;
int H[100000];

int main(){
    cin>>N;
    rep(i,N) cin>>H[i];

    int ans=0;
    int sum=0;
    rep(i,N-1){
        if(H[i]>=H[i+1]){
            sum++;
        }else{
            ans=max(ans,sum);
            sum=0;
        }
    }
    ans=max(ans,sum);

    cout<<ans<<endl;
}