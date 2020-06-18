#include <iostream>
#include "IntMatrix.h"

using namespace mtm;

IntMatrix::IntMatrix(const Dimensions& dimensions, int value)
{
    dim_row = dimensions.getRow();
    dim_col = dimensions.getCol();
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
    for (int i = 0; i < dim_row; ++i)
    {
        delete[] row[i];
    }
    delete[] row;
}

IntMatrix IntMatrix::Identity(const Dimensions dim) {
    IntMatrix matrix = IntMatrix(dim);
    row = new int*[matrix.dim_row];
    for (int i = 0; i < matrix.dim_row; ++i) {
        row[i][i] = 1;
    }
    return matrix;
}

std::ostream& mtm::operator<<(std::ostream& os, const IntMatrix& matrix) {
    int* flatMatrix = new int[matrix.size()];
    int counter = 0;
    Dimensions dims(matrix.height(), matrix.width());
    for (int i = 0; i < matrix.height(); ++i) {
        for (int j = 0; j < matrix.width(); ++j) {
            flatMatrix[counter++] = matrix.row[i][j];
        }
    }
    os << (printMatrix(flatMatrix, dims));
    return os;
}

int IntMatrix::width() const {
    return dim_col;
}

int IntMatrix::height() const {
    return dim_row;
}

int IntMatrix::size() const {
    return dim_row*dim_col;
}

IntMatrix& IntMatrix::operator=(const IntMatrix& matrix)
{
    if(this == & matrix)
    {
        return *this;
    }
    for (int i = 0; i < dim_row; ++i)
    {
        delete[] row[i];
    }
    delete[] row;
    dim_row = matrix.height();
    dim_col = matrix.width();
    //allocating rows
    row = new int *[dim_row];
    //allocating cols
    for (int i = 0; i < dim_row; ++i)
    {
        row[i] = new int[dim_col];
    }
    //setting new values
    for (int j = 0; j < dim_row; ++j)
    {
        for (int i = 0; i < dim_col; ++i)
        {
            row[j][i] = matrix.row[j][i];
        }
    }
    return *this;
}

IntMatrix IntMatrix::transpose() const
{
    Dimensions d(this->width(),this->height());
    IntMatrix matrix(d);
    for (int j = 0; j < matrix.height(); ++j)
    {
        for (int i = 0; i < matrix.width(); ++i)
        {
            matrix.row[j][i] = row[i][j];
        }
    }
    return matrix;
}

IntMatrix mtm::operator+(const IntMatrix &matrix1, const IntMatrix &matrix2)
{
    Dimensions d(matrix1.height(),matrix1.width());
    IntMatrix matrix(d);
    for (int i = 0; i < matrix.height(); ++i) {
        for (int j = 0; j < matrix.width(); ++j) {
            matrix.row[i][j] = matrix1.row[i][j] + matrix2.row[i][j];
        }
    }
    return matrix;
}

IntMatrix IntMatrix::operator-() const {
    Dimensions d(this->height(),this->width());
    IntMatrix matrix(d);
    for (int j = 0; j < matrix.height(); ++j)
    {
        for (int i = 0; i < matrix.width(); ++i)
        {
            matrix.row[j][i] = -row[j][i];
        }
    }
    return matrix;
}
