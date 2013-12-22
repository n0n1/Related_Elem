#include "array.h"
#include <iostream>
using namespace std;

Array::Array(int x, int y, bool _cin)
{
    width = x; height = y;
    p_array = new boolArray*[width];
    for(int i=0; i<width; i++) p_array[i]= new boolArray[height];
    for(int i=0; i<width; i++)
        for(int j=0; j<height; j++){
            if (_cin==true) {
                cin >> p_array[i][j].value;
                p_array[i][j].valueBool=false;
                p_array[i][j].Used=false;
            }
        }
}

Array::Array(int x, int y, int _value)
{
    width = x; height = y;
    p_array = new boolArray*[width];
    for(int i=0; i<width; i++) p_array[i]= new boolArray[height];
    for(int i=0; i<width; i++)
        for(int j=0; j<height; j++){
            p_array[i][j].value=_value;
            p_array[i][j].valueBool=false;
            p_array[i][j].Used=false;
        }
}

Array::Array(const Array &_array)
{
    width = _array.width; height = _array.height;
    p_array = new boolArray*[width];
    for(int i=0; i<width; i++) p_array[i]= new boolArray[height];
    for(int i=0; i<width; i++)
            for(int j=0; j<height; j++){
                p_array[i][j]=_array.p_array[i][j];
            }
}

Array::~Array()
{
    for(int i=0; i<width; i++) delete[] p_array[i];
    delete[] p_array;
}

 Array::boolArray Array::getElem(int ind_x, int ind_y)
{
     return p_array[ind_x][ind_y];
 }

 void Array::setElem(int ind_x, int ind_y,int _value)
 {
     p_array[ind_x][ind_y].value = _value;
 }

 void Array::setElem(int ind_x, int ind_y, int _value, bool _valueBool)
 {
     p_array[ind_x][ind_y].value = _value;
     p_array[ind_x][ind_y].valueBool= _valueBool;
 }

 void Array::setElem(int ind_x, int ind_y, bool _valueBool)
 {
     p_array[ind_x][ind_y].valueBool= _valueBool;
 }

 void Array::setUsElem(int ind_x, int ind_y, bool _value)
 {
     p_array[ind_x][ind_y].Used= _value;
 }

//найти все различные переменные
 list<int> Array::findVariableAll()
 {
     list<int> vars;
     for(int i=0; i<width; i++)
         for(int j=0; j<height; j++){
             vars.push_back(p_array[i][j].value);
         }
    vars.sort();
    vars.unique();
    return vars;
 }

// создаст логическую матрицу для эл-та _value
 void Array::logicArray(const int _value)
 {
     for(int i=0; i<width; i++)
         for(int j=0; j<height; j++){
             if (p_array[i][j].value==_value)
                 p_array[i][j].valueBool=true;
             else
                 p_array[i][j].valueBool=false;
         }
 }
// вернет кол-во (сумму вхождений) переменной _value в матрицу.
 int Array::sumVar(int _value)
 {
    int sum=0;
    for(int i=0; i<width; i++)
        for(int j=0; j<height; j++)
            if (p_array[i][j].value==_value){
                sum+=1;
            }
    return sum;
 }

 bool Array::sumstr(int ind_x)
 {
     bool sum;
     for(int j=0; j<height; j++)
         sum +=p_array[ind_x][j].valueBool;
     return sum;
 }

 // найти первый встречающийся элемент (нужно оптимизировать)
 // вернет номер строки, в которой находится эл.
 int Array::findFirstElem()
 {
     int value;
     for(int i=0; i<width; i++)
         if (sumstr(i) == 0) continue;
          else{value=i; break;}
     return value;
 }
// вернет позицию первого эл. в строки X
 int Array::findFirstElem(int x)
 {
   int value;
   for(int j=0; j<height; j++)
     if (p_array[x][j].valueBool == true) {value=j; break;}
   return value;
 }
// возвращает самый последний связной эл. в строке, относительно эл.-Y
 int Array::findFirstElem(int x, int y)
 {
     int value;
     for(int j=y; y>=0; j--)
      if (p_array[x][j].valueBool == false) {value = j+1; break;}
     return value;
 }
 void Array::syncRelatedArray()
 {
     for(int i=0; i<width; i++)
         for(int j=0; j<height; j++)
             if(p_array[i][j].Used == true){
                 p_array[i][j].valueBool=false;
                 p_array[i][j].Used=false;
             }
 }

 // передается позиция текущего элемента.
 int Array::stepUp(int x, int y)
 {
     int sum = 0;
     for(int i=x; i>=0; i=i-1)
         if(p_array[i][y].valueBool == true){
           if(p_array[i][y].Used == false){
                sum++;
                p_array[i][y].Used=true;
           }
         }else break;
     return sum;
 }

 // передается позиция текущего элемента.
 int Array::stepRight(int x, int y)
 {
    int sum = 0;
    for(int i=y; i<width; i++)
        if(p_array[x][i].valueBool == true){
          sum += stepUp(x,i);
          if(p_array[x][i].Used == false){
                sum++;
                p_array[x][i].Used=true;
          }
        }else break;
    return sum;
 }
// необходимо чтоб эл. A[x][y] был Used, иначе вернет false
 bool Array::isDownElem(int x,int y)
 {
     bool flag=false;
     for(int i=y; i<width; i++)
         if(p_array[x][i].Used == true){
             if((x+1) != height){
                 if(p_array[x][i].valueBool == p_array[x+1][i].valueBool ){
                     flag=true;
                     return flag;
                     break;
                 }
             } else break;
         } else break;
    return flag;
 }
void Array::print() const
{
    cout << "matrix:\n";
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            cout << p_array[i][j].value<< " | ";
        }
        cout << "\n";
    }
    cout << "logic_matrix:\n";
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            cout << p_array[i][j].valueBool<< " | ";
        }
        cout << "\n";
    }
}

void Array::printArray() const
{
    cout << "matrix:\n";
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            cout << p_array[i][j].value<< " | ";
        }
        cout << "\n";
    }
}

void Array::printLogicArray() const
{
    cout << "logic_matrix:\n";
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            cout << p_array[i][j].valueBool<< " | ";
        }
        cout << "\n";
    }
}

void Array::printRelatedArray() const
{
    cout << "related_matrix:\n";
    for(int i=0; i<width; i++){
        for(int j=0; j<height; j++){
            cout << p_array[i][j].Used<< " | ";
        }
        cout << "\n";
    }
}

