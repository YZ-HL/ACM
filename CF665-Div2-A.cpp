#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        if(n >= k)
            printf("%d\n", (((n & 1) && (k & 1)) || ((!(n & 1)) && (!(k & 1)))) ? 0 : 1);
        else
            printf("%d\n", k-n);
    }
    system("pause");
    return 0;
}
