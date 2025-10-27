/*
Problem Name: Minimum Euclidean Distance
Problem Link: https://cses.fi/problemset/task/2194/
Idea:
Complexity:
Resource: https://www.youtube.com/watch?v=kCLGVat2SHk
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

    P& operator+=(const P &t) { x += t.x; y += t.y; return *this; }
    P& operator-=(const P &t) { x -= t.x; y -= t.y; return *this; }
    P& operator*=(ftype t) { x *= t; y *= t; return *this; }
    P& operator/=(ftype t) { x /= t; y /= t; return *this; }

    P operator+(const P &t) const { return P(*this) += t; }
    P operator-(const P &t) const { return P(*this) -= t; }
    P operator*(ftype t) const { return P(*this) *= t; }
    P operator/(ftype t) const { return P(*this) /= t; }

    bool operator == (P a) const { return sign(a.x - x) == 0 && sign(a.y - y) == 0; }
    bool operator != (P a) const { return !(*this == a); }
    bool operator < (P a) const { return sign(a.x - x) == 0 ? y < a.y : x < a.x; }
    bool operator > (P a) const { return sign(a.x - x) == 0 ? y > a.y : x > a.x; }
    P perp() const { return P(y, -x); } // 90° rotation clockwise Or P(y, -x) depending on the desired direction.
};

P operator*(ftype a, P b) {return b * a;}
inline ftype dot(P a, P b) {return a.x * b.x + a.y * b.y;}
inline ftype cross(P a, P b) {return a.x * b.y - a.y * b.x;}
ftype norm(P a) {return dot(a, a);}
double abs(P a) {return sqrt(norm(a));}
double proj(P a, P b) {return dot(a, b) / abs(b);}
double angle(P a, P b) {return acos(dot(a, b) / abs(a) / abs(b));}
P intersect(P a1, P d1, P a2, P d2) {return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;}

bool comparex(P a, P b) { return a.x < b.x; }
bool comparey(P a, P b) { return a.y < b.y; }
ll dist(P a, P b) { return norm(a - b); }

pair<P, P> closestAmongThree(P a, P b, P c) {
    ll d1 = dist(a, b);
    ll d2 = dist(b, c);
    ll d3 = dist(a, c);
    ll mn = min({d1, d2, d3});
    if (mn == d1) return {a, b};
    else if (mn == d2) return {b, c};
    else return {a, c};
}

pair<P, P> closest(vector<P>& points, ll st, ll en) {
    if (st + 1 == en) return {points[st], points[en]};
    if (st + 2 == en) return closestAmongThree(points[st], points[st + 1], points[en]);

    ll mid = st + (en - st) / 2;

    pair<P, P> left = closest(points, st, mid);
    pair<P, P> right = closest(points, mid + 1, en);
    ll left_d = dist(left.first, left.second);
    ll right_d = dist(right.first, right.second);
    ll d = min(left_d, right_d);
    pair<P, P> ans = (d == left_d) ? left : right;

    vector<P> middle;
    for (int i = st; i <= en; i++)
        if ((points[i].x - points[mid].x) * (points[i].x - points[mid].x) < d)
            middle.push_back(points[i]);
    sort(middle.begin(), middle.end(), comparey);

    for (int i = 0; i < (int)middle.size(); i++) {
        for (int j = i + 1; j < (int)middle.size() && 
             (middle[j].y - middle[i].y) * (middle[j].y - middle[i].y) < d; j++) {
            ll dst = dist(middle[i], middle[j]);
            if (dst < d) {
                ans = {middle[i], middle[j]};
                d = dst;
            }
        }
    }
    return ans;
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
        vector<P> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
        sort(points.begin(), points.end(), comparex);
        pair<P, P> ans = closest(points, 0, n - 1);
        cout << dist(ans.first, ans.second) << '\n';
    }
    return 0;
}