/*
Problem Name: Polygon Area
Problem Link: https://cses.fi/problemset/task/2191/
Idea:
Complexity:
Resource: Competitive Programmer’s Handbook - Page 271
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
         cout << PolygonArea(polygon, n) << "\n";
    }
    return 0;
}