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
        class iterator;
        class const_iterator;
        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const;
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

    class IntMatrix::iterator{
        IntMatrix* matrix;
        int index;
        friend class IntMatrix;
        iterator(IntMatrix* matrix, int index);
    public:
        int& operator*();
        iterator& operator++(); // prefix (++it)
        iterator operator++(int);
        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;
        iterator(const iterator&) = default;
        iterator& operator=(const iterator&) = default;
    };
    class IntMatrix::const_iterator{
        const IntMatrix* matrix;
        int index;
        friend class IntMatrix;
        const_iterator(const IntMatrix* matrix, int index);
    public:
        const int& operator*() const;
        const_iterator& operator++(); // prefix (++it)
        const_iterator operator++(int);
        bool operator==(const const_iterator& it) const;
        bool operator!=(const const_iterator& it) const;
        const_iterator(const const_iterator&) = default;
        const_iterator& operator=(const const_iterator&) = default;
    };
}
#endif //HW3_INTMATRIX_H
