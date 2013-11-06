#ifndef ARRAY_H
#define ARRAY_H
#include <string>
#include <list>
#include <iostream>
using namespace std;
class Array
{


public:
    struct boolArray {
        int value; // значение
        bool Used; // использован
        bool valueBool; // логическое значение
    };

    explicit Array(int x=DefaultArraySize, int y=DefaultArraySize,  bool _cin=false); // default
    Array(int x, int y, int _value);
    Array(const Array &_array); // copy
    virtual ~Array();

    struct boolArray getElem(int ind_x,int ind_y) ;
    void setElem(int ind_x, int ind_y, int _value);
    void setElem(int ind_x, int ind_y, int _value,bool _valueBool);
    void setElem(int ind_x, int ind_y, bool _valueBool);
    void setUsElem(int ind_x, int ind_y, bool _value);
    // найти все уникальные
    list<int> findVariableAll();
    // кол-во эл. матрицы
    int sizeArray() const {return width*height;}
    //высота [y]
    int sizeHeight() const {return height;}
    // ширина [x]
    int sizeWidth() const {return width;}

    void print() const;
protected:
    static const int DefaultArraySize = 4;
    int width,height; // [x,y]
    struct boolArray **p_array; // матрица

};

#endif // ARRAY_H
