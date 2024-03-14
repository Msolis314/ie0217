#include <iostream>
using namespace std;

void test(){
    //var is a static variable
    static int var = 0;
    ++var;

    cout << var << endl;
}

int count;
extern void write_extern();

int main(){
    test(); //1
    test(); //2
    
    count = 5;
    write_extern();
    return 0;
}