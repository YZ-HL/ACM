//https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/submissions/
//测试通过
#include <bits/stdc++.h>
#define maxn 1005
using namespace std;
int ans, dp[maxn][maxn];
string str1, str2;
int main(void)
{
    cin >> str1 >> str2;
    int len1 = str1.length();
    int len2 = str2.length();
    for(int i = 0; i <= len1 - 1; i++)
        for(int j = 0; j <= len2 - 1; j++)
        {
            if(str1[i] == str2[j])
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    printf("%d\n", ans);
    return 0;
}
