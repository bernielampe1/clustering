template <typename T> T Vec<T>::sum() {
    T sum = 0;
    for(u32 i = 0; i < _n; i++) sum += _data[i];
    return sum;
}

template <typename T> T Vec<T>::prod() {
    T sum = 0;
    for(u32 i = 0; i < _n; i++) sum *= _data[i];
    return sum;
}

template <typename T> Vec<T> Vec<T>::abs() {
    Vec<T> v(_n);
    for(u32 i = 0; i < _n; i++) v._data[i] = abs(_data[i]);
    return v;
}

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
