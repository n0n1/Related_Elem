#include <iostream>
#include <array.h>
using namespace std;

int main()
{

    Array a(3,3,0,true);
    Array b(a);
    b.print();
    return 0;
}

