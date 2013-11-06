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
