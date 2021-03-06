#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
using namespace std;
int pos, ans[maxn + maxn];
char str[maxn];
int main(void)
{
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i <= len - 1; i++)
    {
        int now = str[i] - 'a' + 1;
        if(now > 10 && now != 20)
            ans[++pos] = now / 10,
            ans[++pos] = now % 10;
        else
            ans[++pos] = now;
    }
    if(len == pos)
    {
        int flag = 0;
        for(int i = 1; i <= pos - 1; i++)
            if(ans[i] * 10 + ans[i + 1] <= 26 && ans[i + 1] < 10)
            {
                flag = i;
                break;
            }
        if(!flag)
            printf("-1");
        else
            for(int i = 1; i <= pos; i++)
            {
                if(i == flag)
                    putchar('a' + ans[i] * 10 + ans[i + 1] - 1), i++;
                else
                    putchar('a' + ans[i] - 1);
            }
        return 0;
    }
    for(int i = 1; i <= pos; i++)
        printf("%c", ans[i] + 'a' - 1);
    return 0;
}