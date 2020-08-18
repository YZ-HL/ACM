#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 100005
using namespace std;
int n, a[maxn];
int seq[maxn], used[maxn], ans[maxn];
int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int s = 0, ansc = 0;
        memset(seq, 0, sizeof(seq));
        memset(used, 0, sizeof(used));
        memset(ans, 0, sizeof(ans));

        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int pos = 1;
        for (int i = 1; i <= n * 2; i++)
        {
            if(s == a[pos])
            {
                pos++;
            }
            else if(s < a[pos])
            {
                seq[i] = 1;
                s++;
            }
        }
        for (int i = 1; i <= n * 2; i++)
        {
            int p = i, flag = 0, cnt = 1;
            if(!seq[i])
            {
                while(!flag)
                {
                    if(seq[p] && used[p])
                        cnt++;
                    if(seq[p] && !used[p])
                    {
                        flag = p;
                    }
                    p--;
                }
                used[flag] = 1;
                ans[++ansc] = cnt;
            }
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        putchar('\n');
    }
    system("pause");
    return 0;
}
