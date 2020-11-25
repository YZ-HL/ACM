#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
#define eps 1e-1
using namespace std;
int na, nb, maxx1, maxx2;
double c1[maxn], c2[maxn], Q[maxn], R[maxn];
void printPoly(double *c, int s){
    int num = 0;
    for(int i = 0; i <= s; i++)
        if(fabs(c[i]) > eps)    num++;
    if(!num)
    {
        printf("0 0 0.0\n");
        return;
    }
    printf("%d", num);
    for(int i = s; i >= 0; i--)
    {
        if(fabs(c[i]) > eps)
            printf(" %d %.1lf", i, c[i]);
    }
    putchar('\n');
}
int main(void)
{
    scanf("%d", &na);
    for(int i = 1; i <= na; i++)
    {
        int e, c;
        scanf("%d %d", &e, &c);
        c1[e] = c;    maxx1 = max(maxx1, e);
    }
    scanf("%d", &nb);
    for(int i = 1; i <= nb; i++)
    {
        int e, c;
        scanf("%d %d", &e, &c);
        c2[e] = c;    maxx2 = max(maxx2, e);
    }
    int t1 = maxx1, t2 = maxx2;
    while(t1 >= t2)
    {
        double d = 1.0 * c1[t1] / c2[t2];
        Q[t1 - t2] = d;
        for(int i = t1, j = t2; j >= 0; i--, j--)
            c1[i] -= c2[j] * d;
        while(fabs(c1[t1]) <= eps)    t1--;
    }
    printPoly(Q, maxx1 - maxx2);
    printPoly(c1, t1);
    return 0;
}
