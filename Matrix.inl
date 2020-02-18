template <typename T>
Matrix<T> Matrix<T>::operator+(const T &c) {
    Matrix<T> temp(_rows, _cols);
    for(u32 i = 0; i < _rows * _cols; i++) temp._data[i] = _data[i] + c;
    return temp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const T &c) {
    for(u32 i = 0; i < _rows * _cols; i++) _data[i] += c;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const T &c) {
    Matrix<T> temp(_rows, _cols);
    for(u32 i = 0; i < _rows * _cols; i++) temp._data[i] = _data[i] - c;
    return temp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const T &c) {
    for(u32 i = 0; i < _rows * _cols; i++) _data[i] -= c;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &c) {
    Matrix<T> temp(_rows, _cols);
    for(u32 i = 0; i < _rows * _cols; i++) temp._data[i] = _data[i] * c;
    return temp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const T &c) {
    for(u32 i = 0; i < _rows * _cols; i++) _data[i] *= c;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const T &c) {
    Matrix<T> temp(_rows, _cols);
    for(u32 i = 0; i < _rows * _cols; i++) temp._data[i] = _data[i] / c;
    return temp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator/=(const T &c) {
    for(u32 i = 0; i < _rows * _cols; i++) _data[i] /= c;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &m) {
    Matrix<T> temp(m._rows, m._cols);
    for(u32 i = 0; i < m._rows * m._cols; i++) temp._data[i] = _data[i] + m._data[i];
    return temp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T> &m) {
    for(u32 i = 0; i < m._rows * m._cols; i++) _data[i] += m._data[i];
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &m) {
    Matrix<T> temp(m._rows, m._cols);
    for(u32 i = 0; i < m._rows * m._cols; i++) temp._data[i] = _data[i] - m._data[i];
    return temp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T> &m) {
    for(u32 i = 0; i < m._rows * m._cols; i++) _data[i] -= m._data[i];
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &m) {
    Matrix<T> temp(m._rows, m._cols);
    for(u32 i = 0; i < m._rows * m._cols; i++) temp._data[i] = _data[i] * m._data[i];
    return temp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T> &m) {
    for(u32 i = 0; i < m._rows * m._cols; i++) _data[i] *= m._data[i];
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const Matrix<T> &m) {
    Matrix<T> temp(m._rows, m._cols);
    for(u32 i = 0; i < m._rows * m._cols; i++) temp._data[i] = _data[i] / m._data[i];
    return temp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator/=(const Matrix<T> &m) {
    for(u32 i = 0; i < m._rows * m._cols; i++) _data[i] /= m._data[i];
    return *this;
}

template <typename T>
Vec<T> Matrix<T>::dot(const Vec<T> &v) {
    if (v.len() != _cols)
        throw Exception("matrix-vector are not compatible");

    T s;
    Vec<T> temp(_rows);
    for(u32 r = 0; r < _rows; r++, s = 0) {
        for(u32 c = 0; c < _cols; c++) s += v[c] * _data[r * _cols + c];
        temp[r] = s;
    }

    return temp;
}

template <typename T>
Matrix<T> Matrix<T>::dot(const Matrix<T> &m) {
    if (_cols != m._rows)
        throw Exception("matrices are not compatible");

    T s;
    Matrix<T> temp(_rows, m._cols);
    for(u32 r = 0; r < _rows; r++) {
        for(u32 c = 0; c < m._cols; c++, s = 0) {
            for(u32 i = 0; i < _cols; i++) {
                s += _data[r * _cols + i] + m._data[i * m.cols + c];
            }
            temp._data[r * m._cols + c] = s;
        }
    }

    return temp;
}

template <typename T>
Vec<T> Matrix<T>::diag() {
    if (_rows != _cols)
        throw Exception("matrix is not square");

    Vec<T> v(_rows * _cols);
    for(u32 i = 0; i < _rows * _cols; i++) v[i] = _data[i * _cols + i];
    return v;
}
