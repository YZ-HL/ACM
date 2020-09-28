#include <bits/stdc++.h>
#define randoms(a, b) rand()%(b-a+1)+a
using namespace std;
int main(void)
{
    srand(time(NULL));
    freopen("data.in", "w", stdout);
    int t = randoms(1, 5);
    printf("%d\n", t);
    for (int i = 1; i <= t; i++)
    {
        int n = randoms(1, 10);
        printf("%d\n", n);
        for(int j = 1; j <= n; j++)
            printf("%d ", randoms(10000000, 100000000));
        putchar('\n');
    }
    return 0;
}