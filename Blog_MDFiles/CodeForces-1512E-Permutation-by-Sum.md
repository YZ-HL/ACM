---
title: CodeForces 1512E - Permutation by Sum
date: 2021-05-03 01:11:33
tags:
- ACM
- CodeForces
- 构造
- 动态规划
---



### 题意

在一个长度为$n$的排列中选择$k$个数，使得$S=k_1+k_2+\dots+k_n$。<!-- more -->



### 思路

首先，这是一道构造题。

然后，思考怎么样才能凑出来$k$个数，使其和为$S$。

先考虑不合法情况。

最大能凑出的数为$n+(n-1)+\dots+(n-k+1)$；

最小能凑出的数为$1+2+\dots+k$；

考虑最大值和最小值中间的数字，是否所有的数字都能被凑出来？

尝试了一下$n=5,k=3$的情况，$minn=6, maxx=12$，有：

- $1+2+3=6$
- $1+2+4=7$
- $1+2+5=8$
- $1+3+5=9$
- $1+4+5=10$
- $2+4+5=11$
- $3+4+5=12$

可以发现，存在一种构造方式，能够表示出最大最小值中间所有的数字。

这种构造方法具体为：

1. 先找出最小值对应的序列，如$(1,2,3)$，求和为$6$
2. 再找出最大值对应的序列，如$(3,4,5)$，求和为$12$
3. 也就是说，每个数字最大的变化为$(12-6)/3=2$
4. 我们从原先较大的数$(3)$开始做加法，加到这个数字的极限值为止$(3 + 2) = 5$
5. 以此类推，就能够$O(n)$构造出符合要求的答案

在构造出这$k$个数后，可以新建一个$used$数组，标记哪些数字被使用过，以帮助我们输出结果。

**代码：**

```c++
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
```



---



后来，我在题解评论区看到有大佬（[amar277](https://codeforces.com/profile/amar277)）使用动态规划来解决问题。

我尝试了一下，这个动态规划还是比较需要剪枝的，否则很容易$TLE$最后一个点。

设$dp[n][m]$为，当前有$n$个元素，总和为$m$，$-1$代表未访问过，$0$代表不合法，$1$代表存在合法情况。

转移使用记忆化搜索，带三个参数$(now,num,sum)$：

$now$ ：当前我可以选择使用的数字；

$num$：当前还剩多少个数字需要选择；

$sum$：当前还剩多少$S$需要被凑出来；

分为两个操作：

一个是$dfs(now-1,num, sum)$，代表什么也不干，使用$now-1$这个数字再开始决策。

另一个是$dfs(now-1,num-1,sum-now)$，代表选取当前的数字$now$。

然后，利用一个全局变量，存放答案，最后用与上面类似的处理方法输出答案即可。

**代码：**

```c++
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
```



---



### End