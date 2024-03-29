/*
Problem Name: Polygon Lattice Points
Problem Link: https://cses.fi/problemset/task/2193/
Idea: Pick's Theorem
Complexity:
Resource:
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
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

inline ftype cross(P a, P b) {return a.x * b.y - a.y * b.x;}

// here return value is area*2
ftype PolygonArea(vector<P> &polygon, int n) {
    ll area = 0;
    for(int i = 0; i < n; i++) {
        int j = (i+1) % n;
        area+=cross(polygon[i], polygon[j]);
    }
    return abs(area);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
         int n;
         cin >> n;
         vector<P> polygon;
         for(int i = 0; i < n; i++) {
            P p;
            p.read();
            polygon.push_back(p);
         }
         ll boundary = 0;
         for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            P diff = polygon[i] - polygon[j];
            boundary+=__gcd(abs(diff.x), abs(diff.y));
         }
         ll inside = 0;
         ll area = PolygonArea(polygon, n);
         /*
         Pick's theorem
         A = i + (b/2) - 1;
         A = area of the polygon, i = total interior polygon, b = total boundary polygon
         2*i = 2*area + 1 - b;
         */
         inside = (area + 2 - boundary) >> 1;
         cout << inside << " " << boundary << "\n";
    }
    return 0;
}