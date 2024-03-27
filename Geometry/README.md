## Resource
- [CSES Geometry Problem Set | Coding Live! | Errichto](https://www.youtube.com/watch?v=G9QTjWtK_TQ)

## 2D Point Template
```C++
using ftype = ll;

struct P {
    ftype x, y;
    P() {}
    P(ftype x, ftype y): x(x), y(y) {}
    void read() {
        cin >> x >> y;
    }
    P& operator+=(const P &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    P& operator-=(const P &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    P& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }
    P& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }
    P operator+(const P &t) const {return P(*this) += t;}
    P operator-(const P &t) const {return P(*this) -= t;}
    P operator*(ftype t) const {return P(*this) *= t;}
    P operator/(ftype t) const {return P(*this) /= t;}
};
P operator*(ftype a, P b) {return b * a;}
inline ftype dot(P a, P b) {return a.x * b.x + a.y * b.y;}
inline ftype cross(P a, P b) {return a.x * b.y - a.y * b.x;}
ftype norm(P a) {return dot(a, a);}
double abs(P a) {return sqrt(norm(a));}
double proj(P a, P b) {return dot(a, b) / abs(b);}
double angle(P a, P b) {return acos(dot(a, b) / abs(a) / abs(b));}
P intersect(P a1, P d1, P a2, P d2) {return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;}
```