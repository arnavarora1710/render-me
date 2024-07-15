#ifndef _GEO_H
#define _GEO_H

#include <cmath>

template <typename T> class vec2 {
    // can access vec2 as a struct .x, .y or an array [0], [1]
    union {
        struct {T x, y;};
        T raw[2];
    };

    // constructors
    vec2 () : x(0), y(0) {}
    vec2 (T _x, T _y) : x(_x), y(_y) {}
    vec2 (const vec2& v) : x(v.x), y(v.y) {}
    
    // operators
    vec2& operator=(const vec2& v) { x = v.x; y = v.y; return *this; }
    vec2 operator+(const vec2& v) const { return vec2(x+v.x, y+v.y); }
    vec2 operator-(const vec2& v) const { return vec2(x-v.x, y-v.y); }
    vec2 operator*(float f) const { return vec2(x*f, y*f); }
    T operator*(const vec2& v) const { return x*v.x + y*v.y; }
    vec2 operator^(const vec2& v) const { return vec2(y*v.x - x*v.y, x*v.y - y*v.x); }
    T& operator[](const int i) const { return raw[i]; }

    // helper functions
    T norm() const { return std::sqrt(x*x + y*y); }
    vec2& normalize(T l = 1) { *this = (*this)*(l/norm()); return *this; }

    template <class> friend std::ostream& operator<<(std::ostream& s, const vec2<T>& v);
};

template <typename T> std::ostream& operator<<(std::ostream& s, const vec2<T>& v) {
    return s << '(' << v.x << ", " << v.y << ')\n';
}

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<double> vec2d;

template <typename T> class vec3 {
    // can access vec3 as a struct .x, .y, .z or an array [0], [1], [2]
    union {
        struct {T x, y, z;};
        T raw[3];
    };

    // constructors
    vec3 () : x(0), y(0), z(0) {}
    vec3 (T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    vec3 (const vec3& v) : x(v.x), y(v.y), z(v.z) {}
    
    // operators
    vec3& operator=(const vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    vec3 operator+(const vec3& v) const { return vec3(x+v.x, y+v.y, z+v.z); }
    vec3 operator-(const vec3& v) const { return vec3(x-v.x, y-v.y, z-v.z); }
    vec3 operator*(float f) const { return vec3(x*f, y*f, z*f); }
    T operator*(const vec3& v) const { return x*v.x + y*v.y + z*v.z; }
    vec3 operator^(const vec3& v) const { return vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x); }
    T& operator[](const int i) const { return raw[i]; }

    // helper functions
    T norm() const { return std::sqrt(x*x + y*y + z*z); }
    vec3& normalize(T l = 1) { *this = (*this)*(l/norm()); return *this; }

    template <class> friend std::ostream& operator<<(std::ostream& s, const vec3<T>& v);
};

template <typename T> std::ostream& operator<<(std::ostream& s, const vec3<T>& v) {
    return s << '(' << v.x << ", " << v.y << ", " << v.z << ')\n';
}

typedef vec3<int> vec3i;
typedef vec3<float> vec3f;
typedef vec3<double> vec3d;

#endif // _GEO_H