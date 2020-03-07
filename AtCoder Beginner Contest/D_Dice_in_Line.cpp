#include <iostream>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    double* p=new double[N];
    for(int i=0;i<N;i++){
        cin>>p[i];
    }

    double max;
    double previous;
    for(int i=0;i<K;i++){
        previous+=p[i];
    }
    max=previous;

    for(int i=1;i<N-K+1;i++){
        cout<<i<<' '<<i+K-1<<'\n';
        if(previous-p[i-1]+p[i+K-1]>max){
            max=previous-p[i-1]+p[i+K-1];
        }        
    }

    cout<<(max+3)/2;

}