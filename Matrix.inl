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
Matrix<T> Matrix<T>::dot(const Vec<T> &v) {
}

template <typename T>
Matrix<T> Matrix<T>::dot(const Matrix<T> &m) {
}

template <typename T>
Matrix<T> Matrix<T>::normcol(const Matrix<T> &m) {
}

template <typename T>
Matrix<T> Matrix<T>::inverse() {
}

template <typename T>
Matrix<T> Matrix<T>::transpose() {
}

template <typename T>
double Matrix<T>::determinant() {
}

template <typename T>
Vec<T> Matrix<T>::diag() {
}
