#ifndef __VEC_H__
#define __VEC_H__

/* Abstraction of a 2-D vector float */
struct Vec2f_t {
  float v[2];

  // initialize to zero
  Vec2f_t() { v[0] = v[1] = 0.0; }

  // accessor
  float &operator[](const int i) { return (v[i]); }
};

/* Abstraction of a 3-D float vector */
struct Vec3f_t {
  float v[3];

  // initialize to zero
  Vec3f_t() { v[0] = v[1] = v[2] = 0.0; }

  // accessor
  float &operator[](const int i) { return (v[i]); }
};

/* Abstraction of a 4-D float vector */
struct Vec4f_t {
  float v[4];

  // initialize to zero
  Vec4f_t() { v[0] = v[1] = v[2] = v[3] = 0.0; }

  // accessor
  float &operator[](const int i) { return (v[i]); }
};

// for pixels
typedef struct Vec3f_t RGB_t;
typedef struct Vec4f_t RGBA_t;

/* Abstraction for large vectors */
template <typename T> class Vec {
    private:
        unsigned _n;
        T *_data

    public:
        Vec(): _n(0), _data(0) { }

        Vec(unsigned int n): _n(n), _data(0) { init(n); }

        Vec(Vec<T> &v): n(v._n), _data(0) {
            init(n);
            for(int = 0; i < v._n; i++) _data[i] = v._data[i];
        }

        Vec<T>& operator=(const Vec<T> &o) {
            if (this != &o) {
                _n = o._n;
                init(o._n);

                for(unsigned int i = 0; i < o.n; i++) _data[i] = o._data[i];
            }

            return(*this);
        }

        ~Vec() { clear(); }

        void init(const unsigned n) {
            if (_data) clear;

            _n = n;
            _data = new T[_n];
            for(int i = 0; i < n; i++) _data[i] = 0;
        }

        void clear() {
            if (_data) delete [] _data;
            _n = 0;
            _data = 0;
        }

        // accessor
        T &operator[](const unsigned int i) { return (v[i]); }
};

#endif // __VEC_H__
