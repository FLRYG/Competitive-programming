#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

string S;

int main(){
    cin>>S;
    int N=S.size();

    for(int i=0;i<N;i++){
        if(S[i]!=S[N-i-1]){
            cout<<"No";
            return 0;
        }
    }

    for(int i=0;i<(N-1)/2;i++){
        if(S[i]!=S[(N-1)/2-i-1]){
            cout<<"No";
            return 0;
        }
    }

    for(int i=(N+1)/2;i<N;i++){
        if(S[i]!=S[N-(i-(N+1)/2)-1]){
            cout<<"No";
            return 0;
        }
    }

    cout<<"Yes";
}