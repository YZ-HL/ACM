#include <bits/stdc++.h>
#define randoms(a, b) rand()%(b-a+1)+a
using namespace std;
int main(void)
{
    srand(time(NULL));
    freopen("data.in", "w", stdout);
    int n = randoms(50000, 100000);
    printf("%d\n", n);
    for (int i = 1; i <= n; i++)
        printf("%d ", randoms(1, 5));
    return 0;
}