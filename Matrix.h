#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <fstream>
#include <math.h>
#include <string.h>

using namespace std;

#include "Vec.h"

/* Abstraction of simple dense matrix, not optimized */
template <typename T> class Matrix {
private:
  int _rows, cols; // matrix dimensions
  T *data;         // columns in row major order

public:
  Matrix()
      : _rows(0), _cols(0), _data(0)

                                Matrix(const int r, const int c)
      : _rows(r), _cols(c), _data(0) {
    init(r, c);
  }

  Matrix(const Matrix<T> &m) : _rows(r), _cols(c), _data(0) {
    init(r, c);
    for (unsigned int i = 0; i < _rows * _cols; i++)
      _data[i] = m._data[i];
  }

  Matrix<T> &operator=(const Matrix<T> &o) {
    if (this != &o) {
      _rows = o._rows;
      _cols = o._cols;
      init(_rows, _cols);
      for (unsigned int i = 0; i < _rows * _cols; i++)
        _data[i] = m._data[i];
    }

    return (*this);
  }

  ~Matrix() { clear(); }

  void init(const int r, const int c, const T v = 0) {
    if (_data)
      clear();
    _rows = r;
    _cols = c;

    _data = new T[_rows * _cols];
    for (int i = 0; i < _rows * _cols; i++)
      _data[i] = v;
  }

  void clear() {
    if (_data)
      delete[] _data;
    _rows = _cols = 0;
    _data = 0;
  }

  /* accessors */
  int rows() const { return (_rows); }

  int cols() const { return (_rows); }

  T get(int r, int c) const { return (_data[r * _cols + c]); }

  /* init square identity */
  Matrix<T> eye(int d) {
    init(d, d);
    for (int i = 0; i < d; i++)
      _data[i * d + i];
  }

  /* Matrix scalar operations */
  Matrix<T> operator+(const T &c);

  Matrix<T> operator-(const T &c);

  Matrix<T> operator*(const T &c);

  Matrix<T> operator/(const T &c);

  /* Simple composition operators */
  Matrix<T> operator+(const Matrix<T> &m);

  Matrix<T> operator-(const Matrix<T> &m);

  Matrix<T> operator*(const Matrix<T> &m);

  Matrix<T> operator/(const Matrix<T> &m);

  /* More complicated composition operations */
  Matrix<T> dot(const Vec<T> &v);

  Matrix<T> dot(const Matrix<T> &m);

  Matrix<T> normcol(const Matrix<T> &m);

  Matrix<T> inverse();

  Matrix<T> transpose();

  double determinant();

  Vec<T> diag();
};

#include "Matrix.inl"

#endif // __MATRIX_H__
