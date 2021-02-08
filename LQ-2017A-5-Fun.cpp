//HDU1521 母函数再练
#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int n, m, num[maxn];
double c1[maxn], c2[maxn];
int func(int x){
    if(x == 1 || x == 0)
        return 1;
    return x * func(x - 1);
}
int main(void)
{
    while(~scanf("%d %d", &n, &m))
    {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        
        for(int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        for(int i = 0; i <= num[1]; i++)
            c1[i] = 1.0 / func(i), c2[i] = 0;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j <= num[i]; j++)
                for(int k = 0; k + j <= m; k++)
                    c2[k + j] += c1[k] * 1.0 / func(j);
            for(int j = 0; j <= m; j++)
                c1[j] = c2[j], c2[j] = 0;
        }
        printf("%.0lf\n", c1[m] * func(m));
    }
    return 0;
}
