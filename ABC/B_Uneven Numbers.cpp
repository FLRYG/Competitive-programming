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

int main(){
    cin>>N;

    int ans=0;
    for(int i=0;i<=5;i++){
        if(i%2==0 && pow(10,i)<=N && N<pow(10,i+1)){
            ans+=N-pow(10,i)+1;
            break;
        }else if(i%2==0 && pow(10,i+1)<=N){
            ans+=pow(10,i+1)-pow(10,i);
        }
    }

    cout<<ans<<endl;
}