#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        int min = 6*t;
        int m_ang = min % 360;
        double hou = 0.5*t;
        double ang1 = fabs((double)m_ang - hou);
        double ang2 = 360.0 - ang1;
        printf("%d\n", ang1 > ang2 ? (int)(ang2 + 0.5) : (int)(ang1 + 0.5));
    }
    //system("pause");
    return 0;
}
