#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", abs(a-b)/10 + (abs(a-b)%10 ? 1 : 0));
    }
    system("pause");
    return 0;
}
