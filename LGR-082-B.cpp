#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int t, n, dp[3][maxn];
int num1[maxn], num2[maxn];
int read(){
    char ch = getchar();
    while(ch != '0' && ch != '1')   ch = getchar();
    return ch - '0';
}
int main(void)
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)    num1[i] = read();
        for(int i = 1; i <= n; i++)    num2[i] = read();
        
        memset(dp, 0, sizeof(dp));

        if(num1[1] == 1 && num2[1] == 0)    dp[1][1] = 1, dp[2][1] = -1;
        if(num1[1] == 0 && num2[1] == 1)    dp[2][1] = 1, dp[1][1] = -1;

        for(int i = 2; i <= n; i++)
        {
            if(num1[i] == 1 && num1[i - 1] == 0 && dp[1][i - 1] != -1)
            {
                dp[1][i - 1] = -1;
                dp[1][i] = 1;
            }
            else if(num1[i] == 0 && num1[i - 1] == 1 && dp[1][i - 1] != 1)
            {
                dp[1][i - 1] = 1;
                dp[1][i] = -1;
            }

            if(num2[i] == 1 && num2[i - 1] == 0 && dp[2][i - 1] != -1)
            {
                dp[2][i - 1] = -1;
                dp[2][i] = 1;
            }
            else if(num2[i] == 0 && num2[i - 1] == 1 && dp[2][i - 1] != 1)
            {
                dp[2][i - 1] = 1;
                dp[2][i] = -1;
            }
            
            if(num1[i] ^ num2[i] && dp[1][i] == 0 && dp[2][i] == 0)
            {
                if(num1[i] == 0)
                {
                    dp[1][i] = -1;
                    dp[2][i] = 1;
                }
                else
                {
                    dp[1][i] = 1;
                    dp[2][i] = -1;
                }
            }
        }

        int flag = 1;
        
        for(int i = 1; i <= 2; i++)
            for(int j = 1; j <= n; j++)
            {
                if(i == 1 && num1[j] == 1)    flag &= dp[1][j];
                if(i == 2 && num2[j] == 1)    flag &= dp[2][j];
            }
        
        printf(flag ? "RP\n" : "++\n");
    }
    return 0;
}
