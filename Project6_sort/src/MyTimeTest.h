#ifndef mytimetestguard
#define mytimetestguard

#include <vector>
#include <chrono>
#include <cstdlib> 

template<class F, class Arg>
int time_miliseconds(F func, Arg arg){
    auto copyArg = arg;
    auto start = std::chrono::high_resolution_clock::now();
    func(copyArg);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    return duration.count();
}

template<class T>
class TestBench{
public:
    TestBench()=delete;
    TestBench(int num, int sz):numberOfTests(num){
        for(int i = 0; i < sz; i++){
            vec.push_back(rand());
        }
    }
    
    template<class F>
    void test(F func){
        int curr = time_miliseconds(func, vec);
        fast = curr;
        slow = curr;
        mean = curr;
        for(int i = 1; i < numberOfTests; i++){
            curr = time_miliseconds(func, vec);
            if (curr < fast) fast = curr;
            if (curr > slow) slow = curr;
            mean += curr;
        }
        mean /= numberOfTests;
    }
    int fast;
    int slow;
    double mean;
    int numberOfTests;
    std::vector<T> vec;
};


#endif 
