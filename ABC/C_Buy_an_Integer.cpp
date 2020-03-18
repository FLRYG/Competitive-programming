#include <iostream>
#include <string>
using namespace std;

long A,B,X;
long dN;

long digit(long k){
    if(k==0){
        return 1;
    }
    long ans=0;
    long c=1;
    while(k>=c){
        ans++;
        c*=10;
    }
    return ans;
}

long f(long begin,long end){
    if(begin==end){
        return begin;
    }
    long N=(begin+end)/2;
    long res=A*N+B*digit(N);
    if(res<=X){
        return f(N,end);
    }else{
        return f(begin,N);
    }
}

int main(){
    cin>>A>>B>>X;

    long ans=f(0,1'000'000'000);
    
    cout<<ans<<endl;
}