#include <iostream>
#include <algorithm>
using namespace std;

long N,M;
long A[100100];
long B[100100];

long gcd(long a, long b)
{
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b ? gcd(b, a % b) : a;
}

long lcm(long a, long b)
{
    return a * b / gcd(a, b);
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>A[i];
        B[i]=A[i]/2;
    }

    long sta=B[0];
    long two=1;
    while(sta%2==0){
        sta/=2;
        two*=2;
    }
    long l=1;
    for(int k=0;k<N;k++){
        if(B[k]%two==0){
            l=lcm(l,B[k]);
        }else{
            cout<<0<<endl;
            return 0;
        }
    }

    int ans=M/l-M/(l*2);

    cout<<ans;
}