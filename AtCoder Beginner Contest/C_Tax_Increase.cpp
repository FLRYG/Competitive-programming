#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int A,B;
    cin>>A>>B;
    
    int a=ceil(A/0.08);
    int b=ceil(B/0.1);

    int x=a>b?a:b;

    if(floor((A+1)/0.08)<=ceil(B/0.1) ||
        floor((B+1)/0.1)<=ceil(A/0.08))
        x=-1;
    cout<<x;
}
