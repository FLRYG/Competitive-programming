#include <iostream>
using namespace std;

int K;
int a[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2,
 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main(){
    cin>>K;

    cout<<a[K-1]<<endl;
}