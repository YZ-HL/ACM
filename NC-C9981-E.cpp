#include <bits/stdc++.h>
#define maxn 100005
#define pi acos(-1.0)
using namespace std;
double a, r;
int main(void)
{
    scanf("%lf %lf", &a, &r);
    double H = sqrt(6) * a / 12;
    double R = sqrt(max(0.0, r * r - H * H));
    if(R >= sqrt(3) * a / 3)
    {
        printf("%lf", sqrt(3) * a * a);
    }
    else if(R >= sqrt(3) * a / 6)
    {
        
        double g = 2 * (pi / 3 - acos(sqrt(3) * a / 6 / R));
        double d = sqrt(R * R - (sqrt(3) * a / 6) * (sqrt(3) * a / 6));
        double area = 4 * 3 * (2 * d * sqrt(3) * a / 6 / 2 + pi * R * R * g / pi / 2);
        printf("%lf", area);
    }
    else if(r > H)
    {
        printf("%lf", 4 * pi * R * R);
    }
    else
    {
        printf("%lf", 0);
    }
    return 0;
}
