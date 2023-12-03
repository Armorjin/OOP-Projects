#include <iostream>
#include <vector>
#include "MySort.h"
#include "MyTimeTest.h"

template<class T>
void testResult(T tb){
    std::cout << "\nfast : " << tb.fast <<"ms";
    std::cout << "\nslow : " << tb.slow <<"ms";
    std::cout << "\nmean : " << tb.mean << "ms" << std::endl;

}

int main()
{

    TestBench<int> tb1(10, 10'000);
    TestBench<double> tb2(10, 10'000);

    tb1.test<void(*)(std::vector<int>)>(MyQuickSort);
    tb2.test<void(*)(std::vector<double>)>(MyQuickSort);

    std::cout << "Test Result for QuickSort (int and double)" << std::endl;
    std::cout << "<int>";
    testResult(tb1);
    std::cout << "<double>";
    testResult(tb2);


    tb1.test<void(*)(std::vector<int>)>(heapSort);
    tb2.test<void(*)(std::vector<double>)>(heapSort);

    std::cout << "Test Result for heapSort (int and double)" << std::endl;
    std::cout << "<int>";
    testResult(tb1);
    std::cout << "<double>";
    testResult(tb2);

    tb1.test<void(*)(std::vector<int>)>(STDSort);
    tb2.test<void(*)(std::vector<double>)>(STDSort);

    std::cout << "Test Result for STDSort (int and double)" << std::endl;
    std::cout << "<int>";
    testResult(tb1);
    std::cout << "<double>";
    testResult(tb2);

    tb1.test<void(*)(std::vector<int>)>(MyBubbleSort);
    tb2.test<void(*)(std::vector<double>)>(MyBubbleSort);

    std::cout << "Test Result for BubbleSort (int and double)" << std::endl;
    std::cout << "<int>";
    testResult(tb1);
    std::cout << "<double>";
    testResult(tb2);

    return 0;
}