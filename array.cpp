#include "array.h"
#include <iostream>
using namespace std;

Array::Array(int x, int y, int _value, bool _cin)
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
            else{
                p_array[i][j].value = _value;
                p_array[i][j].valueBool=false;
                p_array[i][j].Used=false;
            }
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
