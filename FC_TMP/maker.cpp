#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    srand(time(NULL));
    int num = rand() % 3 + 1;
    freopen("data.txt", "w", stdout);
    while (num--)
    {
        int n = rand() % 4 + 1, d = rand() % 8 + 1;
        printf("%d %d\n", n, d);
        for (int i = 1; i <= n; i++)
            printf("%d %d\n", rand() % 10, rand() % 10);
    }
    printf("%d %d\n", 0, 0);
    return 0;
}