#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, l, r, s, ans[maxn], used[maxn];
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &n, &l, &r, &s);
        for(int i = 1; i <= n; i++)    ans[i] = used[i] = 0;
        int minn = 0, maxx = 0, num = r - l + 1;
        for(int i = 1; i <= num; i++)
            minn += i;
        for(int i = n; i >= n - num + 1; i--)
            maxx += i;
        if(s >= minn && s <= maxx)
        {
            int div = (maxx - minn) / num;
            for(int i = l; i <= r; i++)
                ans[i] = i - l + 1;
            s -= minn;
            int pos = r;
            while(s)
            {
                if(s > div)
                {
                    ans[pos] += div;
                    s -= div;
                    pos--;
                }
                else
                {
                    ans[pos] += s;
                    s = 0;
                }
            }
            for(int i = l; i <= r; i++)
                used[ans[i]] = 1;
            for(int i = 1; i <= n; i++)
            {
                if(ans[i])    continue;
                for(int j = 1; j <= n; j++)
                {
                    if(used[j] == 0)
                    {
                        ans[i] = j;
                        used[j] = 1;
                        break;
                    }
                }
            }
            for(int i = 1; i <= n; i++)
                printf(i == n ? "%d\n" : "%d ", ans[i]);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
