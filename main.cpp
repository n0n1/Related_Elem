#include <iostream>
#include <array.h>
#include <list>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    list<int> variables; // все различные переменные
    list<int>::iterator it;
    Array matrix(3,4,true); // ввод с клавиатуры
    //Array backup(matrix);
    variables=matrix.findVariables();
    matrix.printArray();
    cout<<"\n";
    int variableSum;
    int currentSum;
    for(it=variables.begin(); it != variables.end();it++){
        variableSum = matrix.sumVar(*it);
        currentSum=0; // текущая сумма
        matrix.logicArray(*it);// строим логическую матрицу для эл-та.
        cout<<"for "<<"["<<*it<<"]";
        cout << "\n sumVariable= " << variableSum << "\n";
        matrix.printLogicArray();

        while(currentSum < variableSum){
          int firstX = matrix.findFirstElem();
          for(int i=firstX; i<matrix.sizeWidth(); i++){
            int firstY = matrix.findFirstElem(i);
            if(matrix.getElem(i,firstY).valueBool==true){
                currentSum++;
                matrix.setUsElem(i,firstY,true);
                //currentSumAll += matrix.stepUp(i,first_y);
                currentSum += matrix.stepRight(i,firstY);
                if(matrix.isDownElem(i,firstY) == false) {
                    matrix.printRelatedArray();
                    matrix.syncRelatedArray();
                    break;
                    cout << "\n currentSum " << currentSum <<'\n';
                }
             }
          }
        }
   }
    cout << "\n Done!";
    return 0;
    // для того чтобы востановить логическую матрицу после поиска связных эл.  нужно вызвать logicArray(value_element)
}
