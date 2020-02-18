template <typename T> Vec<T> Vec<T>::operator+(const T &c) {
  Vec<T> v(_n);
  for (u32 i = 0; i < _n; i++)
    v._data[i] = _data[i] + c;
  return v;
}

template <typename T> Vec<T> &Vec<T>::operator+=(const T &c) {
  for (u32 i = 0; i < _n; i++)
    _data[i] += c;
  return *this;
}

template <typename T> Vec<T> Vec<T>::operator-(const T &c) {
  Vec<T> v(_n);
  for (u32 i = 0; i < _n; i++)
    v._data[i] = _data[i] - c;
  return v;
}

template <typename T> Vec<T> &Vec<T>::operator-=(const T &c) {
  for (u32 i = 0; i < _n; i++)
    _data[i] -= c;
  return *this;
}

template <typename T> Vec<T> Vec<T>::operator*(const T &c) {
  Vec<T> v(_n);
  for (u32 i = 0; i < _n; i++)
    v._data[i] = _data[i] * c;
  return v;
}

template <typename T> Vec<T> &Vec<T>::operator*=(const T &c) {
  for (u32 i = 0; i < _n; i++)
    _data[i] *= c;
  return *this;
}

template <typename T> Vec<T> Vec<T>::operator/(const T &c) {
  Vec<T> v(_n);
  for (u32 i = 0; i < _n; i++)
    v._data[i] = _data[i] / c;
  return v;
}

template <typename T> Vec<T> &Vec<T>::operator/=(const T &c) {
  for (u32 i = 0; i < _n; i++)
    _data[i] /= c;
  return *this;
}

template <typename T> Vec<T> Vec<T>::operator+(const Vec<T> &m) {
  if (_n != m._n)
    throw("cannot compose vectors of different dimension");
  Vec<T> v(_n);
  for (u32 i = 0; i < _n; i++)
    v._data[i] = _data[i] + m._data[i];
  return v;
}

template <typename T> Vec<T> &Vec<T>::operator+=(const Vec<T> &m) {
  if (_n != m._n)
    throw("cannot compose vectors of different dimension");
  for (u32 i = 0; i < _n; i++)
    _data[i] += m._data[i];
  return *this;
}

template <typename T> Vec<T> Vec<T>::operator-(const Vec<T> &m) {
  if (_n != m._n)
    throw("cannot compose vectors of different dimension");
  Vec<T> v(_n);
  for (u32 i = 0; i < _n; i++)
    v._data[i] = _data[i] - m._data[i];
  return v;
}

template <typename T> Vec<T> &Vec<T>::operator-=(const Vec<T> &m) {
  if (_n != m._n)
    throw("cannot compose vectors of different dimension");
  for (u32 i = 0; i < _n; i++)
    _data[i] -= m._data[i];
  return *this;
}

template <typename T> Vec<T> Vec<T>::operator*(const Vec<T> &m) {
  if (_n != m._n)
    throw("cannot compose vectors of different dimension");
  Vec<T> v(_n);
  for (u32 i = 0; i < _n; i++)
    v._data[i] = _data[i] * m._data[i];
  return v;
}

template <typename T> Vec<T> &Vec<T>::operator*=(const Vec<T> &m) {
  if (_n != m._n)
    throw("cannot compose vectors of different dimension");
  for (u32 i = 0; i < _n; i++)
    _data[i] *= m._data[i];
  return *this;
}

template <typename T> Vec<T> Vec<T>::operator/(const Vec<T> &m) {
  if (_n != m._n)
    throw("cannot compose vectors of different dimension");
  Vec<T> v(_n);
  for (u32 i = 0; i < _n; i++)
    v._data[i] = _data[i] / m._data[i];
  return v;
}

template <typename T> Vec<T> &Vec<T>::operator/=(const Vec<T> &m) {
  if (_n != m._n)
    throw("cannot compose vectors of different dimension");
  for (u32 i = 0; i < _n; i++)
    _data[i] /= m._data[i];
  return *this;
}
