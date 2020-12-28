#include <iostream>
#include <random>
using namespace std;

int N;
int MIN;
int MAX;

struct Random{
    int SEED;
    Random(int seed){SEED=seed;}
    ~Random(){}
    void setSeed(int seed){SEED=seed;}

};

int main(){
    std::cin>>N>>MIN>>MAX;

    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());

    for (int i = 1; i <= N; ++i) {
        std::uint32_t result = engine();
        int a=result%(MAX-MIN+1)+MIN;
        if(i%10!=0)
            std::cout << a << ' ';
        else
            std::cout << a << ' ' << std::endl;
    }
}