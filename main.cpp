#include <iostream>
#include <array.h>
#include <list>

using namespace std;

int main()
{

    list<int> variableAll; // все различные переменные
    list<int>::iterator it;
    Array matrix(2,4,true); // ввод с клавиатуры
    variableAll=matrix.findVariableAll();
   /* for(it=variableAll.begin(); it != variableAll.end();it++)
        cout << *it << " "; */

    return 0;
}

