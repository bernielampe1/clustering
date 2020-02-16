#ifndef __MATRIX_H__
#define __MATRIX_H__

#include<fstream>
#include<math.h>
#include<string.h>

using namespace std;

#include<Vec.h>

/* Abstraction of matrix */
template <typename T> class Matrix {
private:
    T *data;         // columns in row major order
    int _rows, cols; // matrix dimensions

public:
    Matrix() : _data(0), _rows(0), _cols(0)

    Matrix(const int r, const int c) : _data(0), _rows(r), _cols(c) {
        initzero(r, c);
    }

    Matrix(const Matrix<T> &m) : _data(0), _rows(r), _cols(c) {
        initzero(r, c);
        memcpy(_data, m._data, r * c * sizeof(T));
    }

    void initzero(const int r, const int c) {
        if (_data) {
            clear();
        }

        _rows = r;
        _cols = c;
        _data = new T[_rows * _cols];
        memset(_data, 0, _rows * _cols * sizeof(T));
    }

    void clear() {
        if (_data)
        delete[] _data;
        _rows = _cols = 0;
        _data = 0;
  }
};

#endif // __MATRIX_H__
