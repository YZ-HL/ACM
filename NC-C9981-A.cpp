#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, ans, str[maxn];
void dfs(int now){
    if(now == n + 1)
    {
        int l1 = 'u' - 'a' + 1, flag1 = 0;
        int l2 = 's' - 'a' + 1, flag2 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(str[i] == l1)            flag1 = 1;
            if(flag1 && str[i] == l2)   flag2 = 1;
        }
        if(flag1 && flag2)  ans++;
        return;
    }
    for(int i = 1; i <= 26; i++)
    {
        str[now] = i;
        dfs(now + 1);
    }
}
int main(void)
{
    scanf("%d", &n);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
/*
 * 2 -> 1 (0)
 * 3 -> 76 + 1 = 77 (2)
 * 4 -> 3851 + 76 + 1 = 3928 (3976)
 * 5 -> 162626 + 3851 + 76 + 1 = 166554
 * 6 -> 6181401 + 162626 + 3851 + 76 + 1 = 6347955
 */