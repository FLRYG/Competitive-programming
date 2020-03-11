#include <iostream>
#include <algorithm>
using namespace std;

int N,R;
int X[1000];

int main(){
    cin>>N>>R;
    for(int i=0;i<N;i++){
        cin>>X[i];
    }
    sort(X,X+N);

    int i=0;
    int count=0;
    while(i<N){
        int s=X[i++];
        
        while(i<N && X[i]-s<=R){
            i++;
        }
        int c=X[i-1];

        while(i<N && X[i]-c<=R){
            i++;
        }
        count++;
    }

    cout<<count;
}