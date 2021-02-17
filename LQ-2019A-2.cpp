#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int l1 = 1, l2 = 1, l3 = 1;
    for(int i = 4; i <= 20190324; i++)
    {
        printf("%d %d %d\n", l1, l2, l3);
        system("Pause");
        int now = l1 + l2 + l3;
        l1 = l2; l2 = l3; l3 = now;
        l1 %= 10000; l2 %= 10000; l3 %= 10000;
    }
    printf("%d\n", l3);
    return 0;
}