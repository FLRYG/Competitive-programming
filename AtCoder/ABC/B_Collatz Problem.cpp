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

int s;
unordered_map<int,int> m;

int main(){
    cin>>s;

    int ans;
    int i=0;
    while(true){
        i++;
        if(m[s]==0){
            m[s]++;
        }else{
            ans=i;
            break;
        }

        if(s%2==0){
            s/=2;
        }else{
            s=3*s+1;
        }
    }

    cout<<ans<<endl;
}