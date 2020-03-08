#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> g[100100];
    for(int i=1;i<N;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool b=true;
    for(int i=1;i<N;i++){
        if((int)g[i].size()>=N-1){
            b=false;
        }
    }

    if(b){
        for(int i=0;i<N;i++){
            cout<<3<<' ';
        }
    }else{
        cout<<-1;
    }
}

    /*for(int i=1;i<N;i++){
        int size=(int)g[i].size();
        if(size<2) continue;
        for(int j=0;j<size;j++){
            ans[g[i].at(j)]=3;
        }
    }

    for(int i=1;i<=N;i++){
        cout<<ans[i]<<' ';
    }*/
