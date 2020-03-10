//貪欲法

#include <iostream>
#include <algorithm>
using namespace std;

const int value[6]={1,5,10,50,100,500};
int c[6];
int A;

int main(){
    cin>>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>c[5];
    cin>>A;

    int ans=0;

    for(int i=5;i>=0;i--){
        A-=min(value[i]*c[i],value[i]*(A/value[i]));
        ans++;
    }

    cout<<ans;
}