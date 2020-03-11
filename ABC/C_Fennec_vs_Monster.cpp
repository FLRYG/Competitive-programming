#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> H(N);
    for(int i=0;i<N;i++){
        cin>>H[i];
    }
    sort(H.begin(),H.end());

    long long sum=0;
    for(int i;i<N-K;i++){
        sum+=H[i];
    }

    cout<<sum;
}