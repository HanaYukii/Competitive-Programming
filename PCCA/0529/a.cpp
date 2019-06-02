#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const long double PI = acos(-1.0);
long double cal(long double a, long double b, long double c, long double r) {
    long double cosT = (b * b + c * c - a * a) / (2.0 * b * c);
    long double cosHT = sqrt((cosT + 1) / 2.0);
    long double sinHT = sqrt(1 - cosHT * cosHT);
    long double Long = r / sinHT;
    long double tar = sqrt(Long * Long - r * r);
    return tar;
}
long double area(long double a, long double b, long double c) {
    long double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long double a, b, c, r; cin >> a >> b >> c >> r;
    long double sum = a + b + c - 2 * (cal(a, b, c, r) + cal(b, a, c, r) + cal(c, a, b, r));
    cout << fixed << setprecision(20) << (area(a - cal(b, a, c, r) - cal(c, a, b, r), b - cal(a, b, c, r) - cal(c, a, b, r), c - cal(a, b, c, r) - cal(b, a, c, r)) + sum * r + r * r * PI) / area(a, b, c) << '\n';

}