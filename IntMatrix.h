//
// Created by Ron Dahan on 18/06/2020.
//

#ifndef HW3_INTMATRIX_H
#define HW3_INTMATRIX_H

#include "Auxiliaries.h"

namespace mtm {
    class IntMatrix {
        int** row;
        Dimensions dim;
        Dimensions getDimensions() const;
    public:
        class Iterator;
        Iterator begin() const;
        Iterator end() const;
        explicit IntMatrix(const Dimensions& dimensions, int value = 0);
        ~IntMatrix();
        IntMatrix& operator=(const IntMatrix& matrix);
        int height() const;
        int width() const;
        int size() const;
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix& matrix);
        static IntMatrix Identity(int dim);
        IntMatrix transpose() const ;
        friend IntMatrix operator+(const IntMatrix& matrix1, const IntMatrix& matrix2);
        IntMatrix operator-() const ;
        IntMatrix(const IntMatrix& matrix);
        int& operator()(int row_num,int col_num);
        const int& operator()(int row_num,int col_num) const;
        friend IntMatrix operator-(const IntMatrix& matrix1, const IntMatrix& matrix2);
        IntMatrix& operator+=(const int value);
    };
    std::ostream& operator<<(std::ostream& os, const IntMatrix& matrix);
    IntMatrix operator+(const IntMatrix& matrix1, const IntMatrix& matrix2);
    IntMatrix operator<(IntMatrix& matrix, int num);
    IntMatrix operator<=(IntMatrix& matrix, int num);
    IntMatrix operator>(IntMatrix& matrix, int num);
    IntMatrix operator>=(IntMatrix& matrix, int num);
    IntMatrix operator==(IntMatrix& matrix, int num);
    IntMatrix operator!=(IntMatrix& matrix, int num);
    IntMatrix operator-(const IntMatrix& matrix1, const IntMatrix& matrix2);
    IntMatrix operator+(const IntMatrix& matrix, const int value);
    IntMatrix operator+(const int value, const IntMatrix& matrix);
    bool any(const IntMatrix& matrix);
    bool all(const IntMatrix& matrix);

    class IntMatrix::Iterator{
        const IntMatrix* matrix;
        int index;
        friend class IntMatrix;
        Iterator(const IntMatrix* matrix, int index);
    public:
        const int& operator*() const;
        Iterator& operator++(); // prefix (++it)
        Iterator operator++(int);
        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;
        Iterator(const Iterator&) = default;
        Iterator& operator=(const Iterator&) = default;
    };
}
#endif //HW3_INTMATRIX_H
