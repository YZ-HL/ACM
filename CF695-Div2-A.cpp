#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n;
int num[] = {8, 9, 0, 1, 2, 3, 4, 5, 6, 7};
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n == 1)
            printf("%d\n", 9);
        else if(n == 2)
            printf("%d\n", 98);
        else
        {
            printf("%d", 98);
            for(int i = 1; i <= n - 2; i++)
                printf("%d", num[i % 10]);
            putchar('\n');
        }
    }
    return 0;
}
