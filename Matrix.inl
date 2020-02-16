template <typename T> Matrix<T> operator+(const T &c)

template <typename T> Matrix<T> operator-(const T &c)

template <typename T> Matrix<T> operator*(const T &c)

template <typename T> Matrix<T> operator/(const T &c)

template <typename T> Matrix<T> operator+(const Matrix<T> &m)

template <typename T> Matrix<T> operator-(const Matrix<T> &m)

template <typename T> Matrix<T> operator*(const Matrix<T> &m)

template <typename T> Matrix<T> operator/(const Matrix<T> &m)

template <typename T> Matrix<T> dot(const Vec<T> &v)

template <typename T> Matrix<T> dot(const Matrix<T> &m)

template <typename T> Matrix<T> normcol(const Matrix<T> &m)

template <typename T> Matrix<T> inverse()

template <typename T> Matrix<T> transpose()

template <typename T> double determinant()

template <typename T> Vec<T> diag()
