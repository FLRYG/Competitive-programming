#include <iostream>
#include <random>
using namespace std;

// 整数の乱数を[a,b]の範囲で返す
struct Random_int{
    int seed, min, max;
    mt19937 mt;
    uniform_int_distribution<int> rand;
    Random_int(int _min, int _max,int _seed=121314): min(_min),max(_max),seed(_seed){
        mt.seed(seed);
        uniform_int_distribution<int>::param_type param(min,max);
        rand.param(param);
    }
    int nextInt(){
        return rand(mt);
    }
};

// 実数の乱数を[a,b]の範囲で返す
struct Random_double{
    int seed, min, max;
    mt19937 mt;
    uniform_real_distribution<double> rand;
    Random_double(int _min, int _max,int _seed=121314): min(_min),max(_max),seed(_seed){
        mt.seed(seed);
        uniform_real_distribution<double>::param_type param(min,max);
        rand.param(param);
    }
    double nextDouble(){
        return rand(mt);
    }
};

int main(){
    int t,a,b;
    cin>>t>>a>>b;

    if(t==0){
        Random_int r(a,b);
        for(int i=1;i<=30;i++) cout<<i<<' '<<r.nextInt()<<endl;
    }else{
        Random_double r(a,b);
        for(int i=1;i<=30;i++) cout<<i<<' '<<r.nextDouble()<<endl;
    }
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