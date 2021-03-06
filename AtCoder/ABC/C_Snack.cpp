#include <iostream>
#include <string>
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

    long ans=lcm(A,B);

    cout<<ans<<endl;
}