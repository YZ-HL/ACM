#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
int sgn(double x){
    if (fabs(x) < eps)
        return 0;
    return x < 0 ? -1 : 1;
}
struct Point{
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator + (Point B)  { return Point(x + B.x, y + B.y); }
    Point operator - (Point B)  { return Point(x - B.x, y - B.y); }
    Point operator * (double k) { return Point(x * k, y * k); }
    Point operator / (double k) { return Point(x / k, y / k); }
    //Point operator = (Point B)  { return Point(B.x, B.y); }
    bool operator == (Point B)  { return sgn(x - B.x) == 0 && sgn(y - B.y) == 0; }
};
Point A, B, C, P;
typedef Point Vector;
struct Line{
    Point p1, p2;
    Line() {}
    Line(Point p1, Point p2) : p1(p1), p2(p2) {}
};
double Dot(Vector A, Vector B){
    return A.x * B.x + A.y * B.y;
}
double Cross(Vector A, Vector B){
    return A.x * B.y - A.y * B.x;
}
double Distance(Point A, Point B){
    return hypot(A.x - B.x, A.y - B.y);
}
int Point_Line_relation(Point p, Line v){
    int c = sgn(Cross(p - v.p1, v.p2 - v.p1));
    if (c == 0)
        return 0;
    return c > 0 ? 2 : 1;
}
int Point_Seg_relation(Point p, Line v){
    return sgn(Cross(p - v.p1, v.p2 - v.p1)) == 0 && sgn(Dot(p - v.p1, p - v.p2)) <= 0; 
}
double Area_Triangle(Point A, Point B, Point C){
    return fabs(Cross(B - A, C - A) / 2);
}
void Print_Point(Point A){
    printf("x = %lf, y = %lf\n", A.x, A.y);
}
void Print_Line(Line A){
    printf("x1 = %lf, y1 = %lf, x2 = %lf, y2 = %lf\n", A.p1.x, A.p1.y, A.p2.x, A.p2.y);
}
void Solve(Line N, Point Other){
    Point lf, rt;
    if(fabs(N.p1.x-Other.x) <= eps && fabs(N.p1.y-Other.y) <= eps)
        lf = N.p1, rt = N.p2;
    else
        lf = N.p2, rt = N.p1;
    //Print_Point(lf); Print_Point(rt);
    //Print_Line(N);
    //printf("dd: %lf\n", Area_Triangle(A, B, C));
    while(!(lf == rt))
    {
        //Print_Point(lf); Print_Point(rt);
        Point mid = (lf + rt) / 2;
        double Area_it = Area_Triangle(P, Other, mid);
        //printf("debug: %lf\n", Area_it);
        Area_it < Area_Triangle(A, B, C) / 2 ? lf = mid : rt = mid;
    }
    printf("%lf %lf\n", lf.x, lf.y);
}
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lf %lf", &A.x, &A.y);
        scanf("%lf %lf", &B.x, &B.y);
        scanf("%lf %lf", &C.x, &C.y);
        scanf("%lf %lf", &P.x, &P.y);
        Line AB = Line(A, B); Line BC = Line(B, C); Line AC = Line(A, C);
        
        //printf("debug: %d %d %d\n", Point_Seg_relation(P, AB), Point_Seg_relation(P, AC), Point_Seg_relation(P, BC));
        
        if(!Point_Seg_relation(P, AB) && !Point_Seg_relation(P, AC) && !Point_Seg_relation(P, BC))
        {
            printf("-1\n");
        }
        else
        {
            int flag = 0;
            if(Point_Seg_relation(P, AB) && !flag)
                flag = 1, Distance(P, A) < Distance(P, B) ? Solve(BC, B) : Solve(AC, A);
            if(Point_Seg_relation(P, BC) && !flag)
                flag = 1, Distance(P, B) < Distance(P, C) ? Solve(AC, C) : Solve(AB, B);
            if(Point_Seg_relation(P, AC) && !flag)
                flag = 1, Distance(P, A) < Distance(P, C) ? Solve(BC, C) : Solve(AB, A);            
        } 
    }
}