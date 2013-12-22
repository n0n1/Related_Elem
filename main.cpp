#include <iostream>
#include <array.h>
#include <list>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    list<int> variableAll; // все различные переменные
    list<int>::iterator it;
    Array matrix(3,4,true); // ввод с клавиатуры
    //Array backup(matrix);
    variableAll=matrix.findVariableAll();
    matrix.printArray();
    cout<<"\n";
    int sumVariable; // сумма переменных
    int currentSumAll;
    for(it=variableAll.begin(); it != variableAll.end();it++){
        sumVariable = matrix.sumVar(*it);
        currentSumAll=0; // текущая сумма
        matrix.logicArray(*it);// строим логическую матрицу для эл-та.
        cout<<"for "<<"["<<*it<<"]";
        cout << "\n sumVariable= " << sumVariable << "\n";
        matrix.printLogicArray();

        while(currentSumAll < sumVariable){
          int first_x = matrix.findFirstElem();
          for(int i=first_x; i<matrix.sizeWidth(); i++){
            int first_y = matrix.findFirstElem(i);
            if(matrix.getElem(i,first_y).valueBool==true){
                currentSumAll++;
                matrix.setUsElem(i,first_y,true);
                //currentSumAll += matrix.stepUp(i,first_y);
                currentSumAll += matrix.stepRight(i,first_y);
                if(matrix.isDownElem(i,first_y) == false) {
                    matrix.printRelatedArray();
                    matrix.syncRelatedArray();
                    break;
                    cout << "\n currentSum " << currentSumAll <<'\n';
                }
             }
          }

        }


   }
    cout << "\n Done!";
    return 0;
    // для того чтобы востановить логическую матрицу после поиска связных эл.  нужно вызвать logicArray(value_element)
}
