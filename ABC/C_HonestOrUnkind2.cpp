#include <iostream>
using namespace std;

int N;
int A[15];
int x[15][15];
int y[15][15];

int pow2(int n){
    if(n==0){
        return 1;
    }else{
        return 2*pow2(n-1);
    }
}

bool andm(int i,int j){
    return i&pow2(j);
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        for(int j=0;j<A[i];j++){
            cin>>x[i][j]>>y[i][j];
        }
    }

    int ans=0;
    int all=pow2(N);
    for(int i=0;i<all;i++){
        int count=0;
        for(int j=0;j<N;j++){
            bool honest=andm(i,j);
            if(honest){
                for(int k=0;k<A[j];k++){
                    if(!(andm(i,x[j][k]-1)==y[j][k])){
                        goto a;
                    }
                }
                count++;
            }
        }
        if(count>ans) ans=count;
        a:;
    }

    cout<<ans<<endl;
}