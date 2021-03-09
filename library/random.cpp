#include <iostream>
#include <random>
using namespace std;

// 整数の乱数を[a,b]の範囲で返す
struct Random{
    int seed, min, max;
    mt19937 mt;
    uniform_int_distribution<int> rand;
    Random(int _seed, int _min, int _max): seed(_seed),min(_min),max(_max){
        mt.seed(seed);
        uniform_int_distribution<int>::param_type param(min,max);
        rand.param(param);
    }
    ~Random(){}
    int nextInt(){
        return rand(mt);
    }
};

int main(){
    int N,seed,a,b;
    cin>>N>>seed>>a>>b;

    Random rand(seed,a,b);
    for(int i=0;i<N;i++) cout<<i+1<<": "<<rand.nextInt()<<endl;
}

// int N;
// int MIN;
// int MAX;
// int main(){
//     std::cin>>N>>MIN>>MAX;

//     std::random_device seed_gen;
//     std::mt19937 engine(seed_gen());

//     for (int i = 1; i <= N; ++i) {
//         std::uint32_t result = engine();
//         int a=result%(MAX-MIN+1)+MIN;
//         if(i%10!=0)
//             std::cout << a << ' ';
//         else
//             std::cout << a << ' ' << std::endl;
//     }
// }