//拓展：复习经典DP编辑距离
//跟着：https://blog.csdn.net/weixin_43914593/article/details/105444090 再次复习
//测试通过：https://leetcode-cn.com/problems/edit-distance/submissions/
#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int dp[maxn][maxn];
string word1, word2;
int main(void)
{
    cin >> word1 >> word2;
    int len1 = word1.length();
    int len2 = word2.length();
    for(int i = 0; i <= len1; i++)
        for(int j = 0; j <= len2; j++)
        {
            if(i == 0)    dp[0][j] = j;
            else if(j == 0)    dp[i][0] = i;
            else
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;                    
            }
        }
    printf("%d\n", dp[len1][len2]);
    return 0;
}
