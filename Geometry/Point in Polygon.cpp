/*
Problem Name: Point in Polygon
Problem Link: https://cses.fi/problemset/task/2192/
Idea:
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

bool LineSegmentIntersection(P p1, P p2, P p3, P p4) {
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
    // Check one segment totally on the left or right side of other segment
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

string PointInPolygon(vector<P> &polygon, int n, P &p) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int j = (i+1) % n;
        if(LineSegmentIntersection(polygon[i], polygon[j], p, p)) {
            return "BOUNDARY";
        }
        // Imagine a vertically infinite line from point p to positive infinity.
        // Check if a line from the polygon is totally on the left or right side of the infinite line and makes a positive cross product or positive triangle.
        // Here, "right" means to the right or equal.
        if((polygon[i].x >= p.x && polygon[j].x < p.x && cross(polygon[i]-p, polygon[j]-p) > 0) ||
           (polygon[i].x < p.x && polygon[j].x >= p.x && cross(polygon[j]-p, polygon[i]-p) > 0))
            cnt++;
    }
    if(cnt & 1)return "INSIDE";
    return "OUTSIDE";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    tt = 1;
    // cin >> tt;
    while(tt--) {
         int n, m;
         cin >> n >> m;
         vector<P> polygon;
         for(int i = 0; i < n; i++) {
            P p;
            p.read();
            polygon.push_back(p);
         }
         for(int i = 0; i < m; i++) {
            P p;
            p.read();
            cout << PointInPolygon(polygon, n, p) << "\n";
         }
    }
    return 0;
}