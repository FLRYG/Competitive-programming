#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int AC[100100];
    int WA[100100];
    for(int i=1;i<=N;i++){
        AC[i]=0;
        WA[i]=0;
    }

    int ac=0,wa=0;
    int p;
    string S;
    for(int i=0;i<M;i++){
        cin>>p>>S;
        if(AC[p]==0){
            if(S=="AC"){
                AC[p]=1;
                ac++;
                wa+=WA[p];
            }else{
                WA[p]++;
            }
        }
    }

    cout<<ac<<' '<<wa<<endl;
}