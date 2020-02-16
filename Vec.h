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

#endif // __VEC_H__
