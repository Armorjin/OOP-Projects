#include "ptr.h"
#include "unique_ptr.h"
#include <utility>

//cmake -G  "MinGW Makefiles" ../


void check(){
    my_unique_ptr<int> p1(new int(100));
    my_unique_ptr<int> p2(new int(200));
    my_unique_ptr<int> p3(new int(2));

    std::cout<<"Data p1: "<<*p1<<"\n";
    std::cout<<"Data p2: "<<*p2<<"\n";
    std::cout<<"Data p3: "<<((p3)?"unique ptr":"not unique ptr")<<"\n";

    p2 = std::move(p1);
    p3.release();
    std::cout<<"Data p1: "<<*p1<<"\n";
    std::cout<<"Data p2: "<<*p2<<"\n";
    std::cout<<"Data p3: "<<((p3)?"unique ptr":"not unique ptr")<<"\n";

    p1.swap(p3);
    std::cout<<"Data p1: "<<((p1)?"unique ptr":"not unique ptr")<<"\n";
    std::cout<<"Data p3: "<<((p3)?"unique ptr":"not unique ptr")<<"\n";

}
int main(){

    std::cout<< "Tests\n";
    check();
    return 0;
}