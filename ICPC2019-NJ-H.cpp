#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == 1 && b == 0 && c == 0)
        printf("YES\n0");
    else if(a > b + c)
        printf("YES\n%d", b + c == 0 ? 1 : min(a + b + c, 2 * (b + c) + 1));
    else
        printf("NO");
    return 0;
}