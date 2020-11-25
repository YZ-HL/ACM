#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, g, k, sum;
struct Point{
    char str[20];
    int p;
} P[maxn];
bool cmp(const Point &A, const Point &B){
    if(A.p == B.p)
        return (string)A.str > (string)B.str;
    return A.p > B.p;
}
int main(void)
{
    scanf("%d %d %d", &n, &g, &k);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s %d", P[i].str, &P[i].p);
        if(P[i].p >= g)
            sum += 50;
        else if(P[i].p >= 60)
            sum += 20;
    }
    sort(P+1, P+n+1, cmp);
    printf("%d\n", sum);
    P[0].p = P[1].p;
    for(int i = 1, rk = 1; i <= n; i++)
    {
        if(P[i].p != P[i-1].p)    rk = i;
        if(rk > k)    break;
        printf("%d %s %d\n", rk, P[i].str, P[i].p);
    }
    return 0;
}
