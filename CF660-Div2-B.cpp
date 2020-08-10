#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, cnt;
        scanf("%d", &n);
        cnt = ((n - 1) / 4) + 1;
        for (int i = 1; i <= n-cnt; i++) putchar('9');
        for (int i = 1; i <= cnt; i++)  putchar('8');
        putchar('\n');
    }   
    system("pause");
    return 0;
}