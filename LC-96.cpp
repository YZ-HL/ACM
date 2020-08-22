class Solution {
public:
    #define maxn 1005
    int n, dp[maxn][maxn];
    int numTrees(int n) {
        for (int l = 1; l <= n; l++)
        {
            for (int i = 1; i <= n; i++)
            {
                if(i+l-1 > n)
                    continue;
                if(l == 1)
                {
                    dp[i][i] = 1;
                    continue;
                }
                dp[i][i + l - 1] += dp[i + 1][i + l - 1];
                for (int s = i+1; s <= i + l - 2; s++)
                    dp[i][i + l - 1] += dp[i][s-1]*dp[s+1][i + l - 1];
                dp[i][i + l - 1] += dp[i][i + l - 2];
            }
        }
        return dp[1][n];
    }
};