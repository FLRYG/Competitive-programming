#include <iostream>
#include <string>
using namespace std;

const long MIN=0,MAX=1'000'000'000;
long A,B,X;
long dN;

long digit(long k){
    long ans=0;
    long c=1;
    while(k>=c){
        ans++;
        c*=10;
    }
    return ans;
}

long f(long begin,long end){
    if(end-begin<=1){
        return begin;
    }
    long N=(begin+end)/2;
    long sum=A*N+B*digit(N);
    if(sum<=X){
        return f(N,end);
    }else{
        return f(begin,N);
    }
}

int main(){
    cin>>A>>B>>X;

    if(A*MAX+B*digit(MAX)<=X){
        cout<<MAX<<endl;
        return 0;
    }
    long ans=f(MIN,MAX);
    
    cout<<ans<<endl;
}