#ifndef ARRAY_H
#define ARRAY_H
#include <string>

class Array
{


public:
    struct boolArray {
        int value; // значение
        bool Used; // использован
        bool valueBool; // логическое значение
    };

    explicit Array(int x=DefaultArraySize, int y=DefaultArraySize, int _value=1 , bool _cin=false); // default
    Array(const Array &_array); // copy
    virtual ~Array();

    struct boolArray** getElem(int ind_x,int ind_y) const;
    void setElem(int ind_x,int ind_y, struct boolArray *elem);

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
