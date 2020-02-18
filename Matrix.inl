template <typename T> Matrix<T> Matrix<T>::operator+(const T &c) {
  Matrix<T> temp(_rows, _cols);
  for (u32 i = 0; i < _rows * _cols; i++)
    temp._data[i] = _data[i] + c;
  return temp;
}

template <typename T> Matrix<T> &Matrix<T>::operator+=(const T &c) {
  for (u32 i = 0; i < _rows * _cols; i++)
    _data[i] += c;
  return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator-(const T &c) {
  Matrix<T> temp(_rows, _cols);
  for (u32 i = 0; i < _rows * _cols; i++)
    temp._data[i] = _data[i] - c;
  return temp;
}

template <typename T> Matrix<T> &Matrix<T>::operator-=(const T &c) {
  for (u32 i = 0; i < _rows * _cols; i++)
    _data[i] -= c;
  return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator*(const T &c) {
  Matrix<T> temp(_rows, _cols);
  for (u32 i = 0; i < _rows * _cols; i++)
    temp._data[i] = _data[i] * c;
  return temp;
}

template <typename T> Matrix<T> &Matrix<T>::operator*=(const T &c) {
  for (u32 i = 0; i < _rows * _cols; i++)
    _data[i] *= c;
  return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator/(const T &c) {
  Matrix<T> temp(_rows, _cols);
  for (u32 i = 0; i < _rows * _cols; i++)
    temp._data[i] = _data[i] / c;
  return temp;
}

template <typename T> Matrix<T> &Matrix<T>::operator/=(const T &c) {
  for (u32 i = 0; i < _rows * _cols; i++)
    _data[i] /= c;
  return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator+(const Matrix<T> &m) {
  Matrix<T> temp(m._rows, m._cols);
  for (u32 i = 0; i < m._rows * m._cols; i++)
    temp._data[i] = _data[i] + m._data[i];
  return temp;
}

template <typename T> Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &m) {
  for (u32 i = 0; i < m._rows * m._cols; i++)
    _data[i] += m._data[i];
  return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator-(const Matrix<T> &m) {
  Matrix<T> temp(m._rows, m._cols);
  for (u32 i = 0; i < m._rows * m._cols; i++)
    temp._data[i] = _data[i] - m._data[i];
  return temp;
}

template <typename T> Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &m) {
  for (u32 i = 0; i < m._rows * m._cols; i++)
    _data[i] -= m._data[i];
  return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator*(const Matrix<T> &m) {
  Matrix<T> temp(m._rows, m._cols);
  for (u32 i = 0; i < m._rows * m._cols; i++)
    temp._data[i] = _data[i] * m._data[i];
  return temp;
}

template <typename T> Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &m) {
  for (u32 i = 0; i < m._rows * m._cols; i++)
    _data[i] *= m._data[i];
  return *this;
}

template <typename T> Matrix<T> Matrix<T>::operator/(const Matrix<T> &m) {
  Matrix<T> temp(m._rows, m._cols);
  for (u32 i = 0; i < m._rows * m._cols; i++)
    temp._data[i] = _data[i] / m._data[i];
  return temp;
}

template <typename T> Matrix<T> &Matrix<T>::operator/=(const Matrix<T> &m) {
  for (u32 i = 0; i < m._rows * m._cols; i++)
    _data[i] /= m._data[i];
  return *this;
}

template <typename T> Vec<T> Matrix<T>::dot(const Vec<T> &v) {
  if (v.len() != _cols)
    throw Exception("matrix-vector are not compatible");

  T s;
  Vec<T> temp(_rows);
  for (u32 r = 0; r < _rows; r++, s = 0) {
    for (u32 c = 0; c < _cols; c++)
      s += v[c] * _data[r * _cols + c];
    temp[r] = s;
  }

  return temp;
}

template <typename T> Matrix<T> Matrix<T>::dot(const Matrix<T> &m) {
  if (_cols != m._rows)
    throw Exception("matrices are not compatible");

  T s;
  Matrix<T> temp(_rows, m._cols);
  for (u32 r = 0; r < _rows; r++) {
    for (u32 c = 0; c < m._cols; c++, s = 0) {
      for (u32 i = 0; i < _cols; i++) {
        s += _data[r * _cols + i] + m._data[i * m.cols + c];
      }
      temp._data[r * m._cols + c] = s;
    }
  }

  return temp;
}

template <typename T> Matrix<T> Matrix<T>::transpose() {
  Matrix<T> temp(_cols, _rows);
  for (u32 r = 0; r < _rows; r++) {
    for (u32 c = 0; c < _cols; c++) {
      temp._data[c * _rows + r] = _data[r * _cols + c];
    }
  }
  return temp;
}

template <typename T> Vec<T> Matrix<T>::diag() {
  if (_rows != _cols)
    throw Exception("matrix is not square");

  Vec<T> v(_rows * _cols);
  for (u32 i = 0; i < _rows * _cols; i++)
    v[i] = _data[i * _cols + i];
  return v;
}

template <typename T>
Matrix<T> Matrix<T>::cofactor(const u32 &rp, const u32 &cp) {
  if (_rows <= 1 || _cols <= 1)
    throw Exception("cannot create cofactor matrix");

  u32 i = 0;
  u32 j = 0;
  Matrix<T> cof(_rows - 1, _cols - 1);
  for (u32 r = 0; r < _rows; r++) {
    for (u32 c = 0; c < _cols; c++) {
      if (r != rp && c != cp) {
        cof._data[i * cof._cols + j++] = _data[r * _cols + c];
        if (j == cof._cols) {
          j = 0;
          i++;
        }
      }
    }
  }
}

template <typename T> Matrix<T> Matrix<T>::determinant() {
  if (_rows != _cols)
    throw Exception("cannot compute determinant of non-square matrix");
}

template <typename T> Matrix<T> Matrix<T>::adjoint() {
  s32 sign = 1;
  Matrix<T> adj(_rows, _cols);
  for (u32 r = 0; r < _rows; r++) {
    for (u32 c = 0; c < _cols; c++) {
      Matrix<T> cof = cofactor(r, c);
      sign = ((r + c) % 2) ? 1 : -1;
      adj._data[c * _cols + r] = sign * determinant(dof);
    }
  }
}

template <typename T> Matrix<T> Matrix<T>::inverse() {
  if (_rows != _cols)
    throw Exception("cannot compute inverse of non-square matrix");

  T det = determinant();
  if (det == 0)
    throw Exception("determinant is zero for inverse operation");

  return adjoint() /= det;
}

template <typename T> Vec<T> Matrix<T>::solve(const Vec<T> &b) {
  // solve Ax = b
  if (_rows != b.len())
    throw Exception("the matrix-vector system is not compatible");

  // init sol.
  Vec<T> x(_cols);

  // use cramers rule x_i = det(A_i) / det(A)
  Matrix<T> temp = *this;
  for (u32 i = 0; i < _cols; i++) {
    for (u32 r = 0; r < _rows; r++)
      temp._data[r * _cols + i] = b[r]; // new column
    x[i] = temp.determinant();          // compute det ration
    for (u32 r = 0; r < _rows; r++)
      temp._data[r * _cols + i] = _data[r * _cols + i];
  }
  b /= determinant();

  return x;
}
