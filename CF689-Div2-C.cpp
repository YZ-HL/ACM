#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, m, a[maxn];
struct Pi{
    int r;
    double p;
} P[maxn];
bool cmp(const Pi &A, const Pi &B){
    if(A.r == B.r)
        return A.p > B.p;
    return A.r > B.r;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        int fin = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(i != a[i])
                fin = i;
        }
        for(int i = 1; i <= m; i++)
            scanf("%d %lf", &P[i].r, &P[i].p);
        sort(P+1, P+m+1, cmp);
        double fail = 1.0, ans = 0;
        for(int i = 1; i <= m; i++)
        {
            if(P[i].r < fin)    break;
            ans += fail * P[i].p;
            fail *= (1.0 - P[i].p);
        }
        if(fin == 0)
            printf("%.6lf\n", 1.0);
        else
            printf("%.6lf\n", ans);
    }
    return 0;
}