#include <bits/stdc++.h>
using namespace std;
char str[] = "cab";
int main(void)
{
    int t, n, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++)
            putchar(str[i % 3]);
        putchar('\n');
    }
}