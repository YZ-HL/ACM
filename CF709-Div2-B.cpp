#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, a[maxn];
int diff1 = -1, diff2 = -1, flag, order, sul;
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        flag = sul = 0;
        order = -1;
        diff1 = diff2 = -1;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if(n == 1)
        {
            printf("0\n");
            continue;
        }
        //order = is_sorted(a + 1, a + n + 1);
        for(int i = 2; i <= n; i++)
        {
            int d = abs(a[i] - a[i - 1]);
            if(diff1 == -1)    diff1 = d;
            else if(diff2 == -1 && d != diff1)    diff2 = d;
            else if(d != diff1 && d != diff2)
            {
                flag = -1;
                break;
            }
            if(d == 0 && sul == 0)
            {
                sul = 1;
            }
            else if(sul && d != 0)
            {
                flag = -1;
                break;
            }
            if(order == -1)    order = d;
            else if(order != d)    order = -2;  
        }
        //printf("%d\n", );
        if(flag == -1)    
        {
            printf("-1\n");
        }
        else if(order >= 0 && (is_sorted(a + 1, a + n + 1) || is_sorted(a + 1, a + n + 1, greater<int>())))
        {
            printf("0\n");
        }
        else if(diff1 != -1 && diff2 == -1)    
        {
            int now = a[1], fl = 0, mm = diff1 + diff1, cc = diff1;
            for(int i = 1; i <= n; i++)
            {
                if(now >= mm || now != a[i])
                {
                    fl = -1;
                    break;
                }
                now = (now + cc) % mm;
            }
            if(fl == -1)
                printf("-1\n");
            else
                printf("%d %d\n", mm, cc);
        }
        else if(diff1 != -1 && diff2 != -1)
        {
            int now = a[1], fl = 0, mm = diff1 + diff2, cc;
            for(int i = 2; i <= n; i++)
                if(a[i] - a[i - 1] > 0)
                {
                    cc = a[i] - a[i - 1];
                    break;
                }
            for(int i = 1; i <= n; i++)
            {
                if(now >= mm || now != a[i])
                {
                    fl = -1;
                    break;
                }
                now = (now + cc) % mm;
            }
            if(fl == -1)
                printf("-1\n");
            else
                printf("%d %d\n", mm, cc);
        }
    }
    return 0;
}
