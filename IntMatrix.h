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
    };
    std::ostream& operator<<(std::ostream& os, const IntMatrix& matrix);
    IntMatrix operator+(const IntMatrix& matrix1, const IntMatrix& matrix2);
    IntMatrix operator<(IntMatrix& matrix, int num);
    IntMatrix operator<=(IntMatrix& matrix, int num);
    IntMatrix operator>(IntMatrix& matrix, int num);
    IntMatrix operator>=(IntMatrix& matrix, int num);
    IntMatrix operator==(IntMatrix& matrix, int num);
    IntMatrix operator!=(IntMatrix& matrix, int num);
}
#endif //HW3_INTMATRIX_H
