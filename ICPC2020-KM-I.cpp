#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
const double eps = 1e-8;
int sgn(double x){
    if(fabs(x) < eps)    return 0;
    return x < 0 ? -1 : 1;
}
struct Point{
    double x, y;
    Point(){}
    Point(double _x, double _y){
        x = _x;
        y = _y;
    }
    Point operator -(const Point &B)const{
        return Point(x - B.x, y - B.y);
    }
    double operator ^(const Point &B)const{
        return x * B.y - y * B.x;
    }
    double distance(Point P){
        return hypot(x - P.x, y - P.y);
    }
};
struct Line{
    Point s, e;
    Line(){}
    Line(Point _s, Point _e){
        s = _s;
        e = _e;
    }
    int linecrossseg(Line v){
        int d1 = sgn((e - s) ^ (v.s - s));
        int d2 = sgn((e - s) ^ (v.e - s));
        if((d1 ^ d2) == -2)    return 2;
        return (d1 == 0 || d2 == 0);
    }
    Point crosspoint(Line v){
        double a1 = (v.e - v.s) ^ (s - v.s);
        double a2 = (v.e - v.s) ^ (e - v.s);
        return Point((s.x * a2 - e.x * a1) / (a2 - a1), (s.y * a2 - e.y * a1) / (a2 - a1));
    }
};
int n, m;
Point s, t;
Point windmiles[maxn];
Line road;
vector<Point> seg_crosspoint[maxn];
bool cmp(const Point &A, const Point &B){
    return s.distance(A) < s.distance(B);
}
int main(void)
{
    scanf("%d %d", &n, &m);
    scanf("%lf %lf", &s.x, &s.y);
    scanf("%lf %lf", &t.x, &t.y);
    road = Line(s, t);
    for(int i = 1; i <= n; i++)
    {
        double nx, ny;
        scanf("%lf %lf", &nx, &ny);
        windmiles[i] = Point(nx, ny);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)    continue;
            Point p1 = windmiles[i], p2 = windmiles[j];
            Line nowLine = Line(p1, p2);
            if(nowLine.linecrossseg(road))
            {
                Point cp = nowLine.crosspoint(road);
                seg_crosspoint[i].push_back(cp);
            }
        }
        sort(seg_crosspoint[i].begin(), seg_crosspoint[i].end(), cmp);
    }
    for(int i = 1; i <= m; i++)
    {
        int qh, qk;
        scanf("%d %d", &qh, &qk);
        if(qk > seg_crosspoint[qh].size())
            printf("-1\n");
        else
            printf("%.10lf %.10lf\n", seg_crosspoint[qh][qk - 1].x, seg_crosspoint[qh][qk - 1].y);
    }
    return 0;
}