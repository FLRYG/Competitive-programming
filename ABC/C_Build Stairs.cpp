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

    H[0]--;
    for(int i=0;i<N-1;i++){
        if(H[i]<H[i+1]){
            H[i+1]--;
        }else if(H[i]>H[i+1]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
}