#include <iostream>
#include <cmath>
using namespace std;

#include <random>
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

const double E=2.718281828459045;
const double TIME_LIMIT=2.0;
const double TEMPERATURE0=2e3;
const double TEMPERATURE1=6e2;
const Random_double RAND_DOUBLE(0,1);

double temperature=TEMPERATURE0;

inline void updateTemp(double nowTime){
    nowTime/=TIME_LIMIT;
    temperature=pow(TEMPERATURE0,1-nowTime)*pow(TEMPERATURE1,nowTime);
}

template<class S> bool adopt(S delta){
    if(delta>=0) return true;
    else{
        if(RAND_DOUBLE.nextDouble()<=pow(E,delta/temperature)){
            return true;
        }else{
            return false;
        }
    }
}