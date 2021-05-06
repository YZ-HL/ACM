---
title: CodeForces 1513C - Add One
date: 2021-05-04 21:38:36
tags:
- ACM
- CodeForces
- 动态规划
- 规律
---



### 题意

有$t$组询问，每组询问给出两个数字$n$和$m$，求出数字$n$经过$m$次操作之后的长度。

长度对$1e9+7$取模。

每次操作会使得数字$n$的每个数位都$+1$，且不存在进位，下面给出两个例子：

$$43 \rightarrow 54$$

$$109 \rightarrow 2110$$

<!-- more -->



### 思路

看到这一题，联想到早年写的牛客某题（[两道不错的线性筛题目记录 | YZ_HL's Blog](https://oi-liu.com/2021/02/23/两道不错的线性筛题目记录/)）。

想着会不会也是类似的维护方式，开两个数组，一个记录长度，一个记录取模后的值。

后面发现，取模后的值会影响长度的计算。一时间陷入死循环。

这个时候再回去看看题。嗯，发现**看错了**，不需要求出具体的数取模后的结果，而是数字长度。

那么这个就简单了。在没有进位的情况下，每个数字对长度的贡献是独立的。

那么问题转化为求每个数字的贡献。

我们可以发现，当前数字为$num$时，经过$10-num$次操作，可以变成$10$，此时，又可以分解为$1$和$0$两个子问题。

因此，我们可以设$dfs(num,m)$，$num$为当前数字，$m$为当前剩余的操作数。

转移时，若$m >= 10 - num$：

$dfs(num, m) = dfs(1, m - (10 - num)) + (0, m - (10 - num))$

否则，直接$dfs(num, m)=1$，长度不会发生改变。

这样，我们就只需要考虑长度为$1$的问题，和$10$这个特殊的子问题，就可以求解了。

后面学习题解发现，只需要维护$10$开始，经过$m$次操作，数字的长度$dp[m]$就可以了，不需要像我那样那么复杂。



### 代码

```c++
#include <bits/stdc++.h>
#define maxn 200005
#define int long long
const int mod = 1e9 + 7;
using namespace std;
int t, n, m;
int dp[15][maxn];
int dfs(int num, int m){
    if(m == 0)
        return 1;
    if(~dp[num][m])
        return dp[num][m];
    int val = 0;
    if(10 - num <= m)
        val += dfs(1, m - (10 - num)) + dfs(0, m - (10 - num));
    else
        return 1;
    return dp[num][m] = val;
}
signed main(void)
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &m);
        int ans = 0;
        while(n)
        {
            ans = (ans + dfs(n % 10, m)) % mod;
            n /= 10;
        }
        printf("%lld\n", ans);
    }    
    return 0;
}
```



---



### End

啊，头一次知道原来$CodeForces$还会告诉你哪里溢出了，麻了。

![image-20210504233709247](https://raw.githubusercontent.com/YZ-HL/yz-hl.github.io/master/img/CF1513C-P-S1.png)