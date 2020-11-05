#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int N;
int x[8],y[8];

double dist(int p1,int p2){
    double dx=x[p1]-x[p2];
    double dy=y[p1]-y[p2];
    return sqrt(dx*dx+dy*dy);
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x[i]>>y[i];
    }

    double sum;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            sum+=dist(i,j)*2/N;
        }
    }

    cout<<setprecision(16)<<sum<<endl;
}