#include <iostream>
using namespace std;

int N;
int a[200000];

int main(){
    cin>>N;

    int k=1;
    int ans=0;
    for(int i=0;i<N;i++){
        cin>>a[i];

        if(a[i]==k){
            k++;
        }else{
            ans++;
        }
    }

    if(ans==N){
        cout<<-1<<endl;
        return 0;
    }

    cout<<ans<<endl;
}
