#include <iostream>
using namespace std;

int N,K;
int P[200000];

int main(){
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>P[i];
    }

    int sum=0;
    int ans=0;
    for(int i=0;i<K;i++){
        sum+=P[i];
        ans+=P[i];
    }

    for(int i=0;i<N-K;i++){
        sum-=P[i];
        sum+=P[i+K];
        if(sum>ans){
            ans=sum;
        }
    }

    if((ans+K)%2==0){
        ans=(ans+K)/2;
        cout<<ans<<endl;
    }else{
        ans=(ans+K)/2;
        cout<<ans<<".5"<<endl;
    }
}

/*int main(){
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

}*/