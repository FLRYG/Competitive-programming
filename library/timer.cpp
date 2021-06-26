#include <iostream>
#include <chrono>
using namespace std;

// タイマー(秒)
struct Timer{
    long long int starttime;
    Timer(){}
    ~Timer(){}
    inline long long int nowTime() {
        using namespace std::chrono;
        return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    }
    inline void start(){
        starttime=nowTime();
    }
    inline double getTime(){
        return (nowTime()-starttime)/1e9;
    }
};

int main(){
    Timer timer;
    timer.start();
    cout<<timer.getTime()<<endl;
    int a=0;
    for(int i=0;i<100'000'000;i++) a++;
    cout<<timer.getTime()<<endl;

    return 0;
}
