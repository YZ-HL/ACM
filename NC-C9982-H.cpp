#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, flag = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            printf("%d", flag), flag ^= 1;
        flag ^= 1;
        putchar('\n');
    }
    return 0;
}