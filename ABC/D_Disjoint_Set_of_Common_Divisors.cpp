#include <iostream>
#include <algorithm>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

long A,B;

template<class T>
T gcd(T a, T b)
{
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    
    return b ? gcd(b, a % b) : a;
}

template<class T>
T lcm(T a, T b)
{
    return a * b / gcd(a, b);
}

int main(){
    cin>>A>>B;

    long g=gcd(A,B);
    long div=2;
    long ans=1;
    bool first=true;
    while(g>1){
        if(g%div==0){
            g/=div;
            if(first){
                ans++;
                first=false;
            }
        }else{
            div++;
            first=true;
        }
    }

    cout<<ans<<endl;
}