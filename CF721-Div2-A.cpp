#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int cnt, pow2[maxn];
int t, a;
int main(void)
{
    for(int i = 1; i <= 1e9; i *= 2)
        pow2[cnt++] = i;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &a);
        int pos = lower_bound(pow2, pow2 + cnt, a) - pow2;
        if(a == 1)
            printf("0\n");
        else if(pow2[pos] == a)
            printf("%d\n", pow2[pos] - 1);
        else
           printf("%d\n", pow2[pos - 1] - 1);
    }
    return 0;
}
