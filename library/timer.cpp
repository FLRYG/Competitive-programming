#include <iostream>
#include <chrono>
using namespace std;

// タイマー(ミリ秒)
struct Timer{
    double starttime;
    Timer(){}
    ~Timer(){}
    inline double nowTime() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }
    inline void start(){
        starttime=nowTime();
    }
    inline double getTime(){
        return nowTime()-starttime;
    }
};

int main(){
    Timer timer;
    timer.start();
    cout<<timer.getTime()<<endl;
    int a=0;
    for(int i=0;i<100000000;i++) a++;
    cout<<timer.getTime()<<endl;

    return 0;
}
