#include <bits/stdc++.h>
#define maxn 1000005
using namespace std;
int A, B, C, m, hp[maxn];
struct At{
    int ht;
    int lat, rat, lbt, rbt, lct, rct;
} attack[maxn];
int main(void)
{
    scanf("%d %d %d %d", &A, &B, &C, &m);
    for(int i = 1; i <= A * B * C; i++)    scanf("%d", &hp[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d %d %d %d %d %d %d", &attack[i].lat, &attack[i].rat, &attack[i].lbt, &attack[i].rbt, &attack[i].lct, &attack[i].rct, &attack[i].ht);
    int flag = 0;
    for(int now = 1; now <= m; now++)
    {
        for(int i = attack[now].lat; !flag && i <= attack[now].rat; i++)
        {
            for(int j = attack[now].lbt; !flag && j <= attack[now].rbt; j++)
            {
                for(int k = attack[now].lct; !flag && k <= attack[now].rct; k++)
                {
                    hp[((i - 1) * B + (j - 1)) * C + (k - 1) + 1] -= attack[now].ht;
                    if(hp[((i - 1) * B + (j - 1)) * C + (k - 1) + 1] < 0)
                    {
                        flag = now;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", flag);
    return 0;
}