#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int P[8];
int Q[8];

int E[8];

bool equal(int x[]){
    bool res=true;
    for(int i=0;i<N;i++){
        if(x[i]!=E[i]){
            res=false;
            break;
        }
    }
    return res;
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>P[i];
    }
    for(int i=0;i<N;i++){
        cin>>Q[i];
        E[i]=i+1;
    }

    int p=1,q=1;
    do{
        if(!equal(P))p++;
        else break;
    }while(next_permutation(E,E+N));
    sort(E,E+N);
    do{
        if(!equal(Q))q++;
        else break;
    }while(next_permutation(E,E+N));

    int ans=abs(p-q);
    
    cout<<ans;
}