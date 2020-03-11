#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
int L[20000];

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>L[i];
    }
    //sort(L,L+N);

    ll sum=0;

    while(N>1){
        int min1=0,min2=1;
        if(L[min1]>L[min2]) swap(min1,min2);
        
        for(int i=2;i<N;i++){
            if(L[i]<L[min1]){
                min2=min1;
                min1=i;
            }else if(L[i]<L[min2]){
                min2=i;
            }
        }

        int a=L[min1]+L[min2];
        sum+=a;

        if(min1==N-1) swap(min1,min2);
        L[min1]=a;
        L[min2]=L[N-1];
        N--;
    }

    cout<<sum;
}