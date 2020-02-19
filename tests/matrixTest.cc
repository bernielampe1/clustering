#include<iostream>

using namespace std;

#include "Matrix.h"

int main()
{
    float c = 3.1415927;
    float a[] = {1, 2, 3, 4, 5, 6, 7, 8, -9, -10, -11, -12, -13, 14, 15, 16};

    Vec<float> v0(a, 4);
    Matrix<float> m0(a, 4, 4);
    Matrix<float> m1(a, 4, 4);
    Matrix<float> m2(a, 4, 4);

    cout << m0 << endl;

    // simple matrix compositon operations
    m2 = m0 + m1; cout << m2 << endl;
    m2 = m0 - m1; cout << m2 << endl;
    m2 = m0 * m1; cout << m2 << endl;
    m2 = m0 / m1; cout << m2 << endl;

    m2 += m1; cout << m2 << endl;
    m2 -= m1; cout << m2 << endl;
    m2 *= m1; cout << m2 << endl;
    m2 /= m1; cout << m2 << endl;

    // scalar operations
    m2 = m0 + c; cout << m2 << endl;
    m2 = m0 - c; cout << m2 << endl;
    m2 = m0 * c; cout << m2 << endl;
    m2 = m0 / c; cout << m2 << endl;

    m2 += c; cout << m2 << endl;
    m2 -= c; cout << m2 << endl;
    m2 *= c; cout << m2 << endl;
    m2 /= c; cout << m2 << endl;

    // more advanced operations
    cout << m2.transpose() << endl;
    cout << m2.diag() << endl;
    cout << m2.dot(v0) << endl;
    cout << m2.dot(m1) << endl;
    cout << m2.determinant_1() << endl;
    cout << m2.determinant_2() << endl;
    cout << m2.inverse_1() << endl;
    cout << m2.inverse_2() << endl;
    cout << m2.solve_1(v0) << endl;
    cout << m2.solve_2(v0) << endl;

    return 0;
}
