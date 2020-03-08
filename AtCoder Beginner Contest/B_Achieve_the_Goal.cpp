#include <iostream>
using namespace std;

int main(){
    int N,K,M;
    cin >>N>>K>>M;

    int sum=0;
    int A;
    for(int i=0;i<N-1;i++){
        cin>>A;
        sum+=A;
    }

    int ans;
    ans=M*N-sum;
    if(ans>K) ans=-1;
    else if(ans<0) ans=0;

    cout<<ans<<endl;
}