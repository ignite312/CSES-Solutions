## Resource
- [CSES Geometry Problem Set | Coding Live! | Errichto](https://www.youtube.com/watch?v=G9QTjWtK_TQ)
- [https://victorlecomte.com/cp-geo.pdf](https://victorlecomte.com/cp-geo.pdf)

## 2D Point Template
```C++
using ftype = ll;
const double eps = 1e-9;
const double PI = acos((double)-1.0);
int sign(double x) { return (x > eps) - (x < -eps);}

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
    bool operator == (P a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (P a) const { return !(*this == a); }
    bool operator < (P a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (P a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
};

P operator*(ftype a, P b) {return b * a;}
inline ftype dot(P a, P b) {return a.x * b.x + a.y * b.y;}
inline ftype cross(P a, P b) {return a.x * b.y - a.y * b.x;}
ftype norm(P a) {return dot(a, a);}
double abs(P a) {return sqrt(norm(a));}
double proj(P a, P b) {return dot(a, b) / abs(b);}
double angle(P a, P b) {return acos(dot(a, b) / abs(a) / abs(b));}
P intersect(P a1, P d1, P a2, P d2) {return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;}

bool LineSegmentIntersection(P &p1, P &p2, P &p3, P &p4) {
    // Check if they are parallel
    if(cross(p1-p2, p3-p4) == 0) {
        // If they are not collinear
        if(cross(p2-p1, p3-p1) != 0) {
            return false;
        }
        // Check if they are collinear and do not intersect
        for(int it = 0; it < 2; it++) {
            if(max(p1.x, p2.x) < min(p3.x, p4.x) ||
                max(p1.y, p2.y) < min(p3.y, p4.y)) {
                return false;
            }
            swap(p1, p3), swap(p2, p4);
        }
        return true;
    }
    // Check one segment totally on the left or right side of other segmnent
    for(int it = 0; it < 2; it++) {
        ll sign1 = cross(p2-p1, p3-p1);
        ll sign2 = cross(p2-p1, p4-p1);
        if((sign1 < 0 && sign2 < 0) || (sign1 > 0 && sign2 > 0)) {
            return false;
        }
        swap(p1, p3), swap(p2, p4);
    }
    // For all other case return true
    return true;
}

ftype PolygonArea(vector<P> &Points, int n) {
    ll area = 0;
    for(int i = 0; i < n; i++) {
        int j = (i+1) % n;
        area+=cross(Points[i], Points[j]);
    }
    return abs(area);
}
```