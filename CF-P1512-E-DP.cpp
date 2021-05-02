#include <bits/stdc++.h>
#define maxn 505
using namespace std;
int t, n, l, r, s;
int ans[maxn], used[maxn];
int stk[maxn], top;
int dp[maxn][maxn * maxn / 2];
int dfs(int now, int num, int sum){
    //printf("debug: %d %d %d\n", now, num, sum);
    if(num == 0 && sum == 0)
        return dp[num][sum] = 1;
    else if(now == 0 || num == 0 || sum == 0 || 
            sum > now * (now + 1) / 2 || now < num)
        return 0;
    
    if(~dp[num][sum])
        return dp[num][sum];
    
    //printf("gg");
    int res = dfs(now - 1, num, sum);
    if(res)    return dp[num][sum] = res;
    stk[++top] = now;
    res = dfs(now - 1, num - 1, sum - now);
    if(res)    return dp[num][sum] = res;
    top--;    
    return dp[num][sum] = res;
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        top = 0;
        scanf("%d %d %d %d", &n, &l, &r, &s);
        for(int i = 0; i <= n; i++)
        {
            ans[i] = used[i] = stk[i] = 0;
            for(int j = 0; j <= n * (n + 1) / 2; j++)
                dp[i][j] = -1;
        }
        dfs(n, r - l + 1, s);
        if(top == 0)
        {
            printf("-1\n");
            continue;
        }
        for(int i = l; i <= r; i++)
        {
            ans[i] = stk[i - l + 1]; 
            used[ans[i]] = 1;
        }
        for(int i = 1; i <= n; i++)
        {
            if(ans[i])    continue;
            for(int j = 1; j <= n; j++)
            {
                if(used[j])    continue;
                ans[i] = j;
                used[j] = 1;
                break;
            }
        }
        for(int i = 1; i <= n; i++)
            printf(i == n ? "%d\n" : "%d ", ans[i]);
    }
    return 0;
}
