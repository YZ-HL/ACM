#include <bits/stdc++.h>
using namespace std;
int t, n, m, p;
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &p);
        int cnt = 0;
        while(n >= m)
        {
            cnt++;
            n -= m;
            n += (m * (100 - p)) / 100;
        }
        printf("%d\n", cnt);
    }
    system("pause");
    return 0;
}