#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <math>

#include "Vec.h"
#include "types.h"

/* Abstraction of simple dense matrix, not optimized */
template <typename T> class Matrix {
private:
  T *_data;         // columns in row major order
  u32 _rows, _cols; // matrix dimensions

public:
  Matrix() : _data(0), _rows(0), _cols(0) {}

  Matrix(const u32 r, const u32 c) : _data(0), _rows(r), _cols(c) {
    init(r, c);
  }

  Matrix(const Matrix<T> &m) : _data(0), _rows(m._rows), _cols(m._cols) {
    init(_rows, _cols);
    for (u32 i = 0; i < _rows * _cols; i++)
      _data[i] = m._data[i];
  }

  Matrix<T>(Matrix<T> &&m) : _data(m._data), _rows(m._rows), _cols(m._cols) {
    m._data = 0;
    m._rows = m._cols = 0;
  }

  Matrix<T> &operator=(const Matrix<T> &m) {
    if (this != &m) {
      init(m._rows, m._cols);
      for (u32 i = 0; i < _rows * _cols; i++)
        _data[i] = m._data[i];
    }

    return *this;
  }

  Matrix<T> &operator=(Matrix<T> &&m) {
    if (this != &m) {
      if (_data)
        clear();

      _data = m._data;
      _rows = m._rows;
      _cols = m._cols;

      m._data = 0;
      m._rows = m._cols = 0;
    }

    return *this;
  }

  ~Matrix() { clear(); }

  void init(const u32 r, const u32 c, const T v = 0) {
    T *temp = new T[r * c];

    if (_data)
      clear();
    _rows = r;
    _cols = c;
    _data = temp;

    for (u32 i = 0; i < _rows * _cols; i++)
      _data[i] = v;
  }

  void clear() {
    if (_data)
      delete[] _data;
    _rows = _cols = 0;
    _data = 0;
  }

  /* accessors */
  u32 rows() const { return (_rows); }

  u32 cols() const { return (_cols); }

  T &get(u32 r, u32 c) const { return (_data[r * _cols + c]); }

  T &operator[](u32 i) { return (_data[i]); }

  /* init square identity */
  Matrix<T> eye(u32 d) {
    init(d, d);
    for (u32 i = 0; i < d; i++)
      _data[i * d + i];
  }

  /* Matrix scalar operations */
  Matrix<T> operator+(const T &c);
  Matrix<T> &operator+=(const T &c);

  Matrix<T> operator-(const T &c);
  Matrix<T> &operator-=(const T &c);

  Matrix<T> operator*(const T &c);
  Matrix<T> &operator*=(const T &c);

  Matrix<T> operator/(const T &c);
  Matrix<T> &operator/=(const T &c);

  /* Simple composition operators */
  Matrix<T> operator+(const Matrix<T> &m);
  Matrix<T> &operator+=(const Matrix<T> &m);

  Matrix<T> operator-(const Matrix<T> &m);
  Matrix<T> &operator-=(const Matrix<T> &m);

  Matrix<T> operator*(const Matrix<T> &m);
  Matrix<T> &operator*=(const Matrix<T> &m);

  Matrix<T> operator/(const Matrix<T> &m);
  Matrix<T> &operator/=(const Matrix<T> &m);

  /* More advanced composition operations */
  Matrix<T> transpose();

  Vec<T> diag();

  Vec<T> dot(const Vec<T> &v);

  Matrix<T> dot(const Matrix<T> &m);

  // perform LUP decomp
  void decompLUP(Matrix<T> &L, Matrix<T> &U, u32 &P);

  // return cofactor matrix
  Matrix<T> cofactor(const u32 &rp, const u32 &cp);

  // return adjoint matrix
  Matrix<T> adjoint();

  // compute determinant using LUP decomp
  T determinant();

  // invert using adjoint matrix
  Matrix<T> inverse_1();

  // solve using kramer's method
  Vec<T> solve_1(const Vec<T> &b);

  // invert using LUP decomp
  Matrix<T> inverse_2();

  // solve using LUP decomp
  Vec<T> solve_2(const Vec<T> &b);
};

#include "Matrix.inl"

#endif // __MATRIX_H__
