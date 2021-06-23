#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main(){
    printf("%d\n",RAND_MAX);
    srand(0);

    map<int,int> m;
    for(int i=0;i<100000;i++){
        m[rand()]++;
    }

    for(auto &e:m) printf("%d %d\n",e.first,e.second);

    

    return 0;
} 