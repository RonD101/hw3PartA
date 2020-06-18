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
    cout << m <<endl;
    //IntMatrix m2 = m.transpose();
    cout << m2 << endl;
    cout << m2 + m2 << endl;
    cout << -m << endl;
    m = m2 = m3;
    cout << m << endl;
    cout << m.width() << "*" << m.height() << "=" << m.size() << endl;
    return 0;
}