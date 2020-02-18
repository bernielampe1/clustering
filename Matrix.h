#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "types.h"
#include "Vec.h"

/* Abstraction of simple dense matrix, not optimized */
template <typename T> class Matrix {
private:
  T *_data;         // columns in row major order
  u32 _rows, _cols; // matrix dimensions

public:
  Matrix() : _data(0), _rows(0), _cols(0) { }

  Matrix(const u32 r, const u32 c) : _data(0), _rows(r), _cols(c) {
    init(r, c);
  }

  Matrix(const Matrix<T> &m) : _data(0), _rows(m._rows), _cols(m._cols) {
    init(_rows, _cols);
    for (u32 i = 0; i < _rows * _cols; i++)
      _data[i] = m._data[i];
  }

  Matrix<T> &operator=(const Matrix<T> &m) {
    if (this != &m) {
      _rows = m._rows;
      _cols = m._cols;
      init(_rows, _cols);
      for (u32 i = 0; i < _rows * _cols; i++) _data[i] = m._data[i];
    }

    return (*this);
  }

  ~Matrix() { clear(); }

  void init(const u32 r, const u32 c, const T v = 0) {
    if (_data) clear();
    _rows = r;
    _cols = c;

    _data = new T[_rows * _cols];
    for (u32 i = 0; i < _rows * _cols; i++) _data[i] = v;
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

  T& get(u32 r, u32 c) const { return (_data[r * _cols + c]); }

  T& operator[](u32 i) { return (_data[i]); }

  /* init square identity */
  Matrix<T> eye(u32 d) {
    init(d, d);
    for (u32 i = 0; i < d; i++) _data[i * d + i];
  }

  /* Matrix scalar operations */
  Matrix<T> operator+(const T &c);
  Matrix<T>& operator+=(const T &c);

  Matrix<T> operator-(const T &c);
  Matrix<T>& operator-=(const T &c);

  Matrix<T> operator*(const T &c);
  Matrix<T>& operator*=(const T &c);

  Matrix<T> operator/(const T &c);
  Matrix<T>& operator/=(const T &c);

  /* Simple composition operators */
  Matrix<T> operator+(const Matrix<T> &m);
  Matrix<T>& operator+=(const Matrix<T> &m);

  Matrix<T> operator-(const Matrix<T> &m);
  Matrix<T>& operator-=(const Matrix<T> &m);

  Matrix<T> operator*(const Matrix<T> &m);
  Matrix<T>& operator*=(const Matrix<T> &m);

  Matrix<T> operator/(const Matrix<T> &m);
  Matrix<T>& operator/=(const Matrix<T> &m);

  /* More complicated composition operations */
  Vec<T> dot(const Vec<T> &v);

  Matrix<T> dot(const Matrix<T> &m);

  Matrix<T> transpose();

  Vec<T> diag();

  Matrix<T> inverse();

  Matrix<T> adj();

  T det();
};

#include "Matrix.inl"

#endif // __MATRIX_H__
