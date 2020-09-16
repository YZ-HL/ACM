#include <bits/stdc++.h>
#define randoms(a, b) rand()%(b-a+1)+a
using namespace std;
int main(void)
{
    srand(time(NULL));
    freopen("data.in", "w", stdout);
    int n = randoms(1, 1000), m = randoms(1, 1000);
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++)
    {
        int n1 = randoms(1, 1000);
        int n2 = randoms(1, 1000);
        printf("%d %d\n", min(n1, n2), max(n1, n2));
    }
    return 0;
}