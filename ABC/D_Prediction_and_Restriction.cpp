#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int INF=100;
const char table[]={'g','c','p'};

int N,K;
int R,S,P;
string T;

int point(char x){
    if(x=='r'){
        return P;
    }else if(x=='s'){
        return R;
    }else if(x=='p'){
        return S;
    }
}

int main(){
    cin>>N>>K;
    cin>>R>>S>>P;
    cin>>T;

    int sum=0;
    for(int i=0;i<N;i++){
        if(i>=K){
            if(T[i-K]==T[i]){
                T[i]='x';
            }else{
                sum+=point(T[i]);
            }
        }else{
            sum+=point(T[i]);
        }
    }
    cout<<sum<<endl;
}