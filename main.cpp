#include <iostream>
#include "Auxiliaries.h"
#include "IntMatrix.h"

using std::cout;
using std::endl;
using namespace mtm;
int main() {
    Dimensions d(3,4);
    Dimensions d2(8,8);
    IntMatrix m(d,2), m3(d,6), m2(d, 4);
    IntMatrix m4 = m.transpose().transpose();
    m4 = m3;
    m4 = -m4;
    cout << m3 << endl;
    m(1,2) = -7;
    cout << m <<endl;
    m2 = m.transpose();
    cout << m2 << endl;
    cout << m2 + m2 << endl;
    cout << -m << endl;
    m = m2 = m3;
    cout << m << endl;
    m3 = IntMatrix::Identity(4);
    cout << m3 << endl;
    cout << m.width() << "*" << m.height() << "=" << m.size() << endl;
    m2(3,4) = -2;
    cout << m2 << endl;
    IntMatrix mc(m2);
    cout << mc << endl;
    IntMatrix mKS = mc <= 5;
    cout << mKS << endl;
    IntMatrix mG = mc > 6;
    cout << mG << endl;
    IntMatrix mGS = mc >= 6;
    cout << mGS << endl;
    IntMatrix mSS = mc == 6;
    cout << mSS << endl;
    IntMatrix mLS = mc != 6;
    cout << mLS << endl;
    cout << mc << endl;
    m2(1,1) += 1;
    cout << m2 - mc << endl;
    (m2 += -1) += 3;
    cout << m2 << endl;
    cout << -1 + (m2 + 5) << endl;
    cout << "all: " << all(m3) << " \nall+1:" << all(m3 + 1) << endl;
    cout << "any: " << any(m3) << " \nany+1:" << any(IntMatrix(d)) << endl;
//    int* n = new int;
//    *n = 2;
    return 0;
}