#include <iostream>
#include <array.h>
#include <list>
#include <math.h>
#include <vector>
using namespace std;

struct lastInd{
    int x;
    int y;
}elemindx;

int main()
{

    list<int> variableAll; // все различные переменные
    list<int>::iterator it;
    Array matrix(3,3,true); // ввод с клавиатуры
    //Array backup(matrix);
    variableAll=matrix.findVariableAll();
    matrix.printArray();
    cout<<"\n";
    int sumVariable,currentSumAll;
    for(it=variableAll.begin(); it != variableAll.end();it++){
        sumVariable = matrix.sumVar(*it);
        currentSumAll=0; // текущая сумма
        matrix.logicArray(*it);
        cout<<"for "<<"["<<*it<<"]";
        cout << "\n sumVariable= " << sumVariable << "\n";
        matrix.printLogicArray();

        while (currentSumAll != sumVariable){
          int i = matrix.findFirstElem();
          int j = matrix.findFirstElem(i);
          while(i < matrix.sizeHeight()){
              bool downElem = false;
              int downElem_index = -1;
              while(j < matrix.sizeHeight()){
                  if(matrix.getElem(i,j).valueBool == true){ // находим элемент
                      if(matrix.getElem(i,j).Used == false){
                        matrix.setUsElem(i,j,true); // отмечаем что он использован
                        currentSumAll++;
                      }
                      if(j+1 != matrix.sizeHeight()) // проверяем элемент справа
                        if(matrix.getElem(i,j).valueBool == matrix.getElem(i,j+1).valueBool ){
                          if(matrix.getElem(i,j+1).Used == false){
                             matrix.setUsElem(i,j+1,true); currentSumAll++;
                          }
                        }
                      if(j-1>0) // проверяем элемент с лева
                        if(matrix.getElem(i,j).valueBool == matrix.getElem(i,j-1).valueBool ){
                          if(matrix.getElem(i,j-1).Used == false){
                             matrix.setUsElem(i,j-1,true); currentSumAll++;
                          }
                        }
                      if(i-1>0) // проверяем элемент с верху
                        if(matrix.getElem(i,j).valueBool == matrix.getElem(i-1,j).valueBool ){
                          if(matrix.getElem(i-1,j).Used == false){
                             matrix.setUsElem(i-1,j,true); currentSumAll++;
                          }
                        }
                      if(i+1 != matrix.sizeWidth()) // проверяем элемент с низу
                        if(matrix.getElem(i,j).valueBool == matrix.getElem(i+1,j).valueBool ){
                          downElem=true; // если это условие выполняется, то мы знаем что есть элемент в нижней строке
                          // и тогда есть смысл переходить на след строку
                          downElem_index = j;
                          if(matrix.getElem(i+1,j).Used == false)
                             matrix.setUsElem(i+1,j,true); currentSumAll++;
                        }
                }else{ i++; break; // если встречается ноль, то прекаращаем искать элементы
                }
                j++;
          } // while j
              if(downElem == true) { i++; j=matrix.findFirstElem(i,downElem_index);}
              else{
                matrix.printRelatedArray(); // выводим матрицу, с отмечеными эл-ми.
                //Так же на этом месте можно сохрянять в отдельную матрицу (перезагрузить oeprator=)
                matrix.syncRelatedArray(); // зануляем эл-менты которые уже использовали.
                break;
           }

        } //while i

    }
   }
    cout << "Done!";
    return 0;
    // для того чтобы востановить логическую матрицу после поиска связных эл.  нужно вызвать logicArray(value_element)
}
