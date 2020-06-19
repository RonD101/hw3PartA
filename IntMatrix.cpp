#include <iostream>
#include "IntMatrix.h"

using namespace mtm;

IntMatrix::IntMatrix(const Dimensions& dimensions, int value):dim(dimensions)
{
    int dim_row = dimensions.getRow();
    int dim_col = dimensions.getCol();
    //allocating rows
    row = new int *[dim_row];
    //allocating cols
    for (int i = 0; i < dim_row; ++i)
    {
        row[i] = new int[dim_col];
    }
    //setting default value
    for (int j = 0; j < dim_row; ++j)
    {
        for (int i = 0; i < dim_col; ++i)
        {
            row[j][i] = value;
        }
    }
}

IntMatrix::~IntMatrix()
{
    for (int i = 0; i < dim.getRow(); ++i)
    {
        delete[] row[i];
    }
    delete[] row;
}

IntMatrix IntMatrix::Identity(int dim) {
    Dimensions d(dim,dim);
    IntMatrix matrix = IntMatrix(d);
    for (int i = 1; i <= matrix.height(); ++i) {
        matrix(i,i) = 1;
    }
    return matrix;
}

std::ostream& mtm::operator<<(std::ostream& os, const IntMatrix& matrix) {
    int* flatMatrix = new int[matrix.size()];
    int counter = 0;
    Dimensions dims(matrix.height(), matrix.width());
    for (int i = 1; i <= matrix.height(); ++i) {
        for (int j = 1; j <= matrix.width(); ++j) {
            flatMatrix[counter++] = matrix(i,j);
        }
    }
    os << (printMatrix(flatMatrix, dims));
    delete[] flatMatrix;
    return os;
}

int IntMatrix::width() const {
    return dim.getCol();
}

int IntMatrix::height() const {
    return dim.getRow();
}

int IntMatrix::size() const {
    return (this->height())*(this->width());
}

IntMatrix& IntMatrix::operator=(const IntMatrix& matrix)
{
    if(this == & matrix)
    {
        return *this;
    }
    for (int i = 0; i < this->height(); ++i)
    {
        delete[] row[i];
    }
    delete[] row;
    dim = matrix.dim;
    //allocating rows
    row = new int *[this->height()];
    //allocating cols
    for (int i = 0; i < this->height(); ++i)
    {
        row[i] = new int[this->width()];
    }
    //setting new values
    for (int j = 1; j <= this->height(); ++j)
    {
        for (int i = 1; i <= this->width(); ++i)
        {
            (*this)(j,i) = matrix(j,i);
        }
    }
    return *this;
}

IntMatrix mtm::operator<(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 1; j <= matrix_new.height(); ++j)
    {
        for (int i = 1; i <= matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) < num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}

IntMatrix mtm::operator<=(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 1; j <= matrix_new.height(); ++j)
    {
        for (int i = 1; i <= matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) <= num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}
IntMatrix mtm::operator>(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 1; j <= matrix_new.height(); ++j)
    {
        for (int i = 1; i <= matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) > num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}
IntMatrix mtm::operator>=(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 1; j <= matrix_new.height(); ++j)
    {
        for (int i = 1; i <= matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) >= num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}
IntMatrix mtm::operator==(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 1; j <= matrix_new.height(); ++j)
    {
        for (int i = 1; i <= matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) == num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}
IntMatrix mtm::operator!=(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 1; j <= matrix_new.height(); ++j)
    {
        for (int i = 1; i <= matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) != num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}

IntMatrix IntMatrix::transpose() const
{
    Dimensions d(this->width(),this->height());
    IntMatrix matrix(d);
    for (int j = 1; j <= matrix.height(); ++j)
    {
        for (int i = 1; i <= matrix.width(); ++i)
        {
            matrix(j,i) = (*this)(i,j);
        }
    }
    return matrix;
}

IntMatrix mtm::operator+(const IntMatrix &matrix1, const IntMatrix &matrix2)
{
    IntMatrix matrix(matrix1.getDimensions());
    for (int i = 1; i <= matrix.height(); ++i) {
        for (int j = 1; j <= matrix.width(); ++j) {
            matrix(i,j) = matrix1(i,j) + matrix2(i,j);
        }
    }
    return matrix;
}

IntMatrix IntMatrix::operator-() const {
    IntMatrix matrix(this->getDimensions());
    for (int j = 1; j <= matrix.height(); ++j)
    {
        for (int i = 1; i <= matrix.width(); ++i)
        {
            matrix(j,i) = -(*this)(j,i);
        }
    }
    return matrix;
}

IntMatrix::IntMatrix(const IntMatrix &matrix):dim(matrix.height(),matrix.width()) {
    //allocating rows
    row = new int *[matrix.height()];
    //allocating cols
    for (int i = 0; i < matrix.height(); ++i)
    {
        row[i] = new int[matrix.width()];
    }
    for (int i = 1; i <= this->height() ; ++i) {
        for (int j = 1; j <= this->width(); ++j) {
            (*this)(i,j) = matrix(i,j);
        }
    }
}

Dimensions IntMatrix::getDimensions() const {
    return this->dim;
}

int& IntMatrix::operator()(int row_num, int col_num) {
    return row[row_num - 1][col_num - 1];
}

const int& IntMatrix::operator()(int row_num, int col_num) const {
    return row[row_num - 1][col_num - 1];
}

IntMatrix mtm::operator-(const IntMatrix &matrix1, const IntMatrix &matrix2) {
    return IntMatrix(matrix1 + -matrix2);
}

IntMatrix& IntMatrix::operator+=(const int value) {
    IntMatrix m(this->getDimensions(),value);
    *this = *this + m;
    return *this;
}

IntMatrix mtm::operator+(const IntMatrix& matrix, const int value){
    IntMatrix m(matrix);
    m += value;
    return m;
}

IntMatrix mtm::operator+(const int value, const IntMatrix& matrix){
    return matrix + value;
}

bool mtm::any(const IntMatrix& matrix)
{
    for (int i = 1; i <= matrix.height(); ++i)
    {
        for (int j = 1; j <= matrix.width(); ++j)
        {
            if(matrix(i,j) != 0)
            {
                return true;
            }
        }
    }
    return false;
}

bool mtm::all(const IntMatrix& matrix)
{
    for (int i = 1; i <= matrix.height(); ++i)
    {
        for (int j = 1; j <= matrix.width(); ++j)
        {
            if(matrix(i,j) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool IntMatrix::Iterator::operator==(const IntMatrix::Iterator &it) const {
    return this->index == it.index;
}

bool IntMatrix::Iterator::operator!=(const IntMatrix::Iterator &it) const {
    return this->index != it.index;
}
