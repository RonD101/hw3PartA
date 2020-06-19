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
    const IntMatrix mc(m2);
    cout << mc << endl;
//    int* n = new int;
//    *n = 2;
    return 0;
}