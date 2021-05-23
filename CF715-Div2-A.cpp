#include <bits/stdc++.h>
#define maxn 500005
using namespace std;
int t, n, cnt1, cnt2, odd[maxn], even[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        cnt1 = cnt2 = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            tmp & 1 ? odd[++cnt1] = tmp : even[++cnt2] = tmp;
        }
        for(int i = 1; i <= cnt1; i++)
            printf("%d ", odd[i]);
        for(int i = 1; i <= cnt2; i++)
            printf("%d ", even[i]);
        putchar('\n');
    }
    return 0;
}
